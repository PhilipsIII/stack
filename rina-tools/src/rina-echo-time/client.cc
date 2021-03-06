//
// Echo Client
//
// Addy Bombeke <addy.bombeke@ugent.be>
// Vincenzo Maffione <v.maffione@nextworks.it>
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//

#include <cstring>
#include <iostream>
#include <sstream>
#include <cassert>
#include <random>
#include <thread>
#include <unistd.h>

#define RINA_PREFIX     "rina-echo-time"
#include <librina/logs.h>

#include "client.h"

using namespace std;
using namespace rina;


static std::chrono::seconds      thres_s   = std::chrono::seconds(9);
static std::chrono::milliseconds thres_ms  = std::chrono::milliseconds(9);
static std::chrono::microseconds thres_us  = std::chrono::microseconds(9);

static string
durationToString(const std::chrono::high_resolution_clock::duration&
                           dur)
{
        std::stringstream ss;

        if (dur > thres_s)
                ss << std::chrono::duration_cast<std::chrono::seconds>(dur).count() << "s";
        else if (dur > thres_ms)
                ss << std::chrono::duration_cast<std::chrono::milliseconds>
                        (dur).count() << "ms";
        else if (dur > thres_us)
                ss << std::chrono::duration_cast<std::chrono::microseconds>
                        (dur).count() << "us";
        else
                ss << std::chrono::duration_cast<std::chrono::nanoseconds>
                        (dur).count() << "ns";

        return ss.str();
}

Client::Client(const string& t_type,
               const string& dif_nm, const string& apn, const string& api,
               const string& server_apn, const string& server_api,
               bool q, unsigned long count,
               bool registration, unsigned int size,
               unsigned int w, int g, int dw) :
        Application(dif_nm, apn, api), test_type(t_type), dif_name(dif_nm),
        server_name(server_apn), server_instance(server_api),
        quiet(q), echo_times(count),
        client_app_reg(registration), data_size(size), wait(w), gap(g),
        dealloc_wait(dw)
{ }

void Client::run()
{
        Flow *flow;

        if (client_app_reg) {
                applicationRegister();
        }
        flow = createFlow();
        if (flow) {
                if (test_type == "ping")
                        pingFlow(flow);
                else if (test_type == "perf")
                        perfFlow(flow);
                else
                        LOG_ERR("Unknown test type '%s'", test_type.c_str());
        }
        if (flow) {
                if (dealloc_wait > 0) {
                        sleep(dealloc_wait);
                }
                destroyFlow(flow);
        }
}

Flow* Client::createFlow()
{
        Flow* flow = nullptr;
        std::chrono::high_resolution_clock::time_point begintp =
                std::chrono::high_resolution_clock::now();
        AllocateFlowRequestResultEvent* afrrevent;
        FlowSpecification qosspec;
        IPCEvent* event;
        uint seqnum;

        if (gap >= 0)
                qosspec.maxAllowableGap = gap;

        if (dif_name != string()) {
                seqnum = ipcManager->requestFlowAllocationInDIF(
                        ApplicationProcessNamingInformation(app_name, app_instance),
                        ApplicationProcessNamingInformation(server_name, server_instance),
                        ApplicationProcessNamingInformation(dif_name, string()),
                        qosspec);
        } else {
                seqnum = ipcManager->requestFlowAllocation(
                        ApplicationProcessNamingInformation(app_name, app_instance),
                        ApplicationProcessNamingInformation(server_name, server_instance),
                        qosspec);
        }

        for (;;) {
                event = ipcEventProducer->eventWait();
                if (event && event->eventType == ALLOCATE_FLOW_REQUEST_RESULT_EVENT
                                && event->sequenceNumber == seqnum) {
                        break;
                }
                LOG_DBG("Client got new event %d", event->eventType);
        }

        afrrevent = dynamic_cast<AllocateFlowRequestResultEvent*>(event);

        flow = ipcManager->commitPendingFlow(afrrevent->sequenceNumber,
                                              afrrevent->portId,
                                              afrrevent->difName);
        if (!flow || flow->getPortId() == -1) {
                LOG_ERR("Failed to allocate a flow");
                return nullptr;
        } else {
                LOG_DBG("[DEBUG] Port id = %d", flow->getPortId());
        }

        std::chrono::high_resolution_clock::time_point eindtp =
                std::chrono::high_resolution_clock::now();
        std::chrono::high_resolution_clock::duration dur = eindtp - begintp;

        if (!quiet) {
                cout << "Flow allocation time = " << durationToString(dur) << endl;
        }

        return flow;
}

void Client::pingFlow(Flow* flow)
{
        char *buffer = new char[data_size];
        char *buffer2 = new char[data_size];
        ulong n = 0;
        random_device rd;
        default_random_engine ran(rd());
        uniform_int_distribution<int> dis(0, 255);

        while (flow) {
                IPCEvent* event = ipcEventProducer->eventPoll();

                if (event) {
                        switch(event->eventType) {
                        case FLOW_DEALLOCATED_EVENT:
                                flow = nullptr;
                                break;
                        default:
                                LOG_INFO("Client got new event %d", event->eventType);
                                break;
                        }
                } else if (n < echo_times) {
                                std::chrono::high_resolution_clock::time_point begintp, endtp;
                                int bytes_read = 0;

                                for (uint i = 0; i < data_size; i++) {
                                        buffer[i] = dis(ran);
                                }

                                begintp = std::chrono::high_resolution_clock::now();
                                flow->writeSDU(buffer, data_size);
                                bytes_read = flow->readSDU(buffer2, data_size);
                                endtp = std::chrono::high_resolution_clock::now();
                                cout << "SDU size = " << data_size << ", seq = " << n <<
                                        ", RTT = " << durationToString(endtp - begintp);
                                if (!((data_size == (uint) bytes_read) &&
                                      (memcmp(buffer, buffer2, data_size) == 0)))
                                        cout << " [bad response]";
                                cout << endl;

                                n++;
                                if (n < echo_times) {
                                        this_thread::sleep_for(std::chrono::milliseconds(wait));
                                }
                } else {
                        break;
                }
        }

        delete [] buffer;
        delete [] buffer2;
}

void Client::perfFlow(Flow* flow)
{
        char *buffer;
        unsigned long n = 0;

        buffer = new char[data_size];
        if (!buffer) {
                LOG_ERR("Allocation of the send buffer failed");

                return;
        }

        for (unsigned int i = 0; i < data_size; i++) {
                buffer[i] = static_cast<char>(i * i);
        }

        while (n < echo_times) {
                flow->writeSDU(buffer, data_size);
                n++;
                if (wait)
                        this_thread::sleep_for(std::chrono::milliseconds(wait));
        }

        delete [] buffer;
}

void Client::destroyFlow(Flow *flow)
{
        DeallocateFlowResponseEvent *resp = nullptr;
        unsigned int seqnum;
        IPCEvent* event;
        int port_id = flow->getPortId();

        seqnum = ipcManager->requestFlowDeallocation(port_id);

        for (;;) {
                event = ipcEventProducer->eventWait();
                if (event && event->eventType == DEALLOCATE_FLOW_RESPONSE_EVENT
                                && event->sequenceNumber == seqnum) {
                        break;
                }
                LOG_DBG("Client got new event %d", event->eventType);
        }
        resp = dynamic_cast<DeallocateFlowResponseEvent*>(event);
        assert(resp);

        ipcManager->flowDeallocationResult(port_id, resp->result == 0);
}
