/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <ostream>
#include <sstream>

#define RINA_PREFIX "common"

#include "logs.h"
#include "config.h"
#include "librina-common.h"
#include "core.h"

namespace rina {

std::string getVersion() {
	return VERSION;
}

/* CLASS APPLICATION PROCESS NAMING INFORMATION */

ApplicationProcessNamingInformation::ApplicationProcessNamingInformation() {
}

ApplicationProcessNamingInformation::ApplicationProcessNamingInformation(
		const std::string & processName,
		const std::string & processInstance) {
	this->processName = processName;
	this->processInstance = processInstance;
}

bool ApplicationProcessNamingInformation::operator==(
		const ApplicationProcessNamingInformation &other) const {
	if (processName.compare(other.processName) != 0) {
		return false;
	}

	if (processInstance.compare(other.processInstance) != 0) {
		return false;
	}

	if (entityName.compare(other.entityName) != 0) {
		return false;
	}

	if (entityInstance.compare(other.entityInstance) != 0) {
		return false;
	}

	return true;
}

bool ApplicationProcessNamingInformation::operator!=(
		const ApplicationProcessNamingInformation &other) const {
	return !(*this == other);
}

ApplicationProcessNamingInformation &
ApplicationProcessNamingInformation::operator=(
		const ApplicationProcessNamingInformation & other){
	if (this != &other){
		processName = other.getProcessName();
		processInstance = other.getProcessInstance();
		entityName = other.getEntityName();
		entityInstance = other.getEntityInstance();
	}

	return *this;
}

bool ApplicationProcessNamingInformation::operator>(
		const ApplicationProcessNamingInformation &other) const {
	int aux = getProcessName().compare(other.getProcessName());
	if (aux > 0) {
		return true;
	} else if (aux < 0) {
		return false;
	}

	aux = getProcessInstance().compare(other.getProcessInstance());
	if (aux > 0) {
		return true;
	} else if (aux < 0) {
		return false;
	}

	aux = getEntityName().compare(other.getEntityName());
	if (aux > 0) {
		return true;
	} else if (aux < 0) {
		return false;
	}

	aux = getEntityInstance().compare(other.getEntityInstance());
	if (aux > 0) {
		return true;
	} else {
		return false;
	}
}

bool ApplicationProcessNamingInformation::operator<=(
		const ApplicationProcessNamingInformation &other) const {
	return !(*this > other);
}

bool ApplicationProcessNamingInformation::operator<(
		const ApplicationProcessNamingInformation &other) const {
	int aux = getProcessName().compare(other.getProcessName());
	if (aux < 0) {
		return true;
	} else if (aux > 0) {
		return false;
	}

	aux = getProcessInstance().compare(other.getProcessInstance());
	if (aux < 0) {
		return true;
	} else if (aux > 0) {
		return false;
	}

	aux = getEntityName().compare(other.getEntityName());
	if (aux < 0) {
		return true;
	} else if (aux > 0) {
		return false;
	}

	aux = getEntityInstance().compare(other.getEntityInstance());
	if (aux < 0) {
		return true;
	} else {
		return false;
	}
}

bool ApplicationProcessNamingInformation::operator>=(
		const ApplicationProcessNamingInformation &other) const {
	return !(*this < other);
}

const std::string & ApplicationProcessNamingInformation::getEntityInstance()
		const {
	return entityInstance;
}

void ApplicationProcessNamingInformation::setEntityInstance(
		const std::string & entityInstance) {
	this->entityInstance = entityInstance;
}

const std::string & ApplicationProcessNamingInformation::getEntityName()
		const {
	return entityName;
}

void ApplicationProcessNamingInformation::setEntityName(
		const std::string & entityName) {
	this->entityName = entityName;
}

const std::string & ApplicationProcessNamingInformation::getProcessInstance()
		const {
	return processInstance;
}

void ApplicationProcessNamingInformation::setProcessInstance(
		const std::string & processInstance) {
	this->processInstance = processInstance;
}

const std::string & ApplicationProcessNamingInformation::getProcessName()
		const {
	return processName;
}

void ApplicationProcessNamingInformation::setProcessName(
		const std::string & processName) {
	this->processName = processName;
}

std::string ApplicationProcessNamingInformation::
getProcessNamePlusInstance(){
	return processName + "-" + processInstance;
}

std::string ApplicationProcessNamingInformation::getEncodedString() {
        return processName + "-" + processInstance +
                        "-" + entityName + "-" + entityInstance;
}

const std::string ApplicationProcessNamingInformation::toString(){
        std::stringstream ss;

        ss<<"Process name: "<<processName;
        ss<<"; Process instance: "<<processInstance<<std::endl;
        ss<<"Entity name: "<<entityName;
        ss<<"; Entity instance: "<<entityInstance;

        return ss.str();
}

/* CLASS FLOW SPECIFICATION */

FlowSpecification::FlowSpecification() {
	averageSDUBandwidth = 0;
	averageBandwidth = 0;
	peakBandwidthDuration = 0;
	peakSDUBandwidthDuration = 0;
	undetectedBitErrorRate = 0;
	partialDelivery = true;
	orderedDelivery = false;
	maxAllowableGap = -1;
	jitter = 0;
	delay = 0;
	maxSDUsize = 0;
}

unsigned int FlowSpecification::getAverageBandwidth() const {
	return averageBandwidth;
}

void FlowSpecification::setAverageBandwidth(unsigned int averageBandwidth) {
	this->averageBandwidth = averageBandwidth;
}

unsigned int FlowSpecification::getAverageSduBandwidth() const {
	return averageSDUBandwidth;
}

void FlowSpecification::setAverageSduBandwidth(
		unsigned int averageSduBandwidth) {
	averageSDUBandwidth = averageSduBandwidth;
}

unsigned int FlowSpecification::getDelay() const {
	return delay;
}

void FlowSpecification::setDelay(unsigned int delay) {
	this->delay = delay;
}

unsigned int FlowSpecification::getJitter() const {
	return jitter;
}

void FlowSpecification::setJitter(unsigned int jitter) {
	this->jitter = jitter;
}

int FlowSpecification::getMaxAllowableGap() const {
	return maxAllowableGap;
}

void FlowSpecification::setMaxAllowableGap(int maxAllowableGap) {
	this->maxAllowableGap = maxAllowableGap;
}

unsigned int FlowSpecification::getMaxSDUSize() const {
	return maxSDUsize;
}

void FlowSpecification::setMaxSDUSize(unsigned int maxSduSize) {
	maxSDUsize = maxSduSize;
}

bool FlowSpecification::isOrderedDelivery() const {
	return orderedDelivery;
}

void FlowSpecification::setOrderedDelivery(bool orderedDelivery) {
	this->orderedDelivery = orderedDelivery;
}

bool FlowSpecification::isPartialDelivery() const {
	return partialDelivery;
}

void FlowSpecification::setPartialDelivery(bool partialDelivery) {
	this->partialDelivery = partialDelivery;
}

unsigned int FlowSpecification::getPeakBandwidthDuration() const {
	return peakBandwidthDuration;
}

void FlowSpecification::setPeakBandwidthDuration(
		unsigned int peakBandwidthDuration) {
	this->peakBandwidthDuration = peakBandwidthDuration;
}

unsigned int FlowSpecification::getPeakSduBandwidthDuration() const {
	return peakSDUBandwidthDuration;
}

void FlowSpecification::setPeakSduBandwidthDuration(
		unsigned int peakSduBandwidthDuration) {
	peakSDUBandwidthDuration = peakSduBandwidthDuration;
}

double FlowSpecification::getUndetectedBitErrorRate() const {
	return undetectedBitErrorRate;
}

void FlowSpecification::setUndetectedBitErrorRate(
		double undetectedBitErrorRate) {
	this->undetectedBitErrorRate = undetectedBitErrorRate;
}

const std::string FlowSpecification::toString() {
        std::stringstream ss;
        ss<<"Jitter: "<<jitter<<"; Delay: "<<delay<<std::endl;
        ss<<"In oder delivery: "<<orderedDelivery;
        ss<<"; Partial delivery allowed: "<<partialDelivery<<std::endl;
        ss<<"Max allowed gap between SDUs: "<<maxAllowableGap;
        ss<<"; Undetected bit error rate: "<<undetectedBitErrorRate<<std::endl;
        ss<<"Average bandwidth (bytes/s): "<<averageBandwidth;
        ss<<"; Average SDU bandwidth (bytes/s): "<<averageSDUBandwidth<<std::endl;
        ss<<"Peak bandwidth duration (ms): "<<peakBandwidthDuration;
        ss<<"; Peak SDU bandwidth duration (ms): "<<peakSDUBandwidthDuration;
        return ss.str();
}

bool FlowSpecification::operator==(const FlowSpecification &other) const {
	if (averageBandwidth != other.getAverageBandwidth()) {
		return false;
	}

	if (averageSDUBandwidth != other.getAverageSduBandwidth()) {
		return false;
	}

	if (peakBandwidthDuration != other.getPeakBandwidthDuration()) {
		return false;
	}

	if (peakSDUBandwidthDuration != other.getPeakSduBandwidthDuration()) {
		return false;
	}

	if (undetectedBitErrorRate != other.getUndetectedBitErrorRate()) {
		return false;
	}

	if (partialDelivery != other.isPartialDelivery()) {
		return false;
	}

	if (orderedDelivery != other.isOrderedDelivery()) {
		return false;
	}

	if (maxAllowableGap != other.getMaxAllowableGap()) {
		return false;
	}

	if (delay != other.getDelay()) {
		return false;
	}

	if (jitter != other.getJitter()) {
		return false;
	}

	if (maxSDUsize != other.getMaxSDUSize()) {
		return false;
	}

	return true;
}

bool FlowSpecification::operator!=(const FlowSpecification &other) const {
	return !(*this == other);
}

/* CLASS FLOW INFORMATION */
bool FlowInformation::operator==(
		const FlowInformation &other) const {
	return getPortId() == other.getPortId();
}

bool FlowInformation::operator!=(
		const FlowInformation &other) const {
	return !(*this == other);
}

const ApplicationProcessNamingInformation&
FlowInformation::getDifName() const {
	return difName;
}

void FlowInformation::setDifName(
		const ApplicationProcessNamingInformation& difName) {
	this->difName = difName;
}

const FlowSpecification& FlowInformation::getFlowSpecification() const {
	return flowSpecification;
}

void FlowInformation::setFlowSpecification(
		const FlowSpecification& flowSpecification) {
	this->flowSpecification = flowSpecification;
}

const ApplicationProcessNamingInformation&
FlowInformation::getLocalAppName() const {
	return localAppName;
}

void FlowInformation::setLocalAppName(
		const ApplicationProcessNamingInformation& localAppName) {
	this->localAppName = localAppName;
}

int FlowInformation::getPortId() const {
	return portId;
}

void FlowInformation::setPortId(int portId) {
	this->portId = portId;
}

const ApplicationProcessNamingInformation&
FlowInformation::getRemoteAppName() const {
	return remoteAppName;
}

void FlowInformation::setRemoteAppName(
		const ApplicationProcessNamingInformation& remoteAppName) {
	this->remoteAppName = remoteAppName;
}

const std::string FlowInformation::toString(){
        std::stringstream ss;

        ss<<"Local app name: "<<localAppName.toString()<<std::endl;
        ss<<"Remote app name: "<<remoteAppName.toString()<<std::endl;
        ss<<"DIF name: "<<difName.getProcessName();
        ss<<"; Port-id: "<<portId<<std::endl;
        ss<<"Flow specification: "<<flowSpecification.toString();

        return ss.str();
}

/* CLASS QoS CUBE */
QoSCube::QoSCube(){
        id = 0;
        averageBandwidth = 0;
        averageSDUBandwidth = 0;
        peakBandwidthDuration = 0;
        peakSDUBandwidthDuration = 0;
        undetectedBitErrorRate = 0;
        partialDelivery = true;
        orderedDelivery = false;
        maxAllowableGap = -1;
        jitter = 0;
        delay = 0;
}

QoSCube::QoSCube(const std::string& name, int id) {
	this->name = name;
	this->id = id;
	averageBandwidth = 0;
	averageSDUBandwidth = 0;
	peakBandwidthDuration = 0;
	peakSDUBandwidthDuration = 0;
	undetectedBitErrorRate = 0;
	partialDelivery = true;
	orderedDelivery = false;
	maxAllowableGap = -1;
	jitter = 0;
	delay = 0;
}

bool QoSCube::operator==(const QoSCube &other) const {
	return (this->id == other.id);
}

bool QoSCube::operator!=(const QoSCube &other) const {
	return !(*this == other);
}

const std::string& QoSCube::getName() const {
	return this->name;
}

void QoSCube::setName(const std::string& name) {
        this->name = name;
}

int QoSCube::getId() const{
	return id;
}

void QoSCube::setId(int id) {
        this->id = id;
}

unsigned int QoSCube::getAverageBandwidth() const {
	return averageBandwidth;
}

void QoSCube::setAverageBandwidth(unsigned int averageBandwidth) {
	this->averageBandwidth = averageBandwidth;
}

unsigned int QoSCube::getAverageSduBandwidth() const {
	return averageSDUBandwidth;
}

void QoSCube::setAverageSduBandwidth(unsigned int averageSduBandwidth) {
	this->averageSDUBandwidth = averageSduBandwidth;
}

unsigned int QoSCube::getDelay() const {
	return delay;
}

void QoSCube::setDelay(unsigned int delay) {
	this->delay = delay;
}

unsigned int QoSCube::getJitter() const {
	return jitter;
}

void QoSCube::setJitter(unsigned int jitter) {
	this->jitter = jitter;
}

int QoSCube::getMaxAllowableGap() const {
	return maxAllowableGap;
}

void QoSCube::setMaxAllowableGap(int maxAllowableGap) {
	this->maxAllowableGap = maxAllowableGap;
}

bool QoSCube::isOrderedDelivery() const {
	return orderedDelivery;
}

void QoSCube::setOrderedDelivery(bool orderedDelivery) {
	this->orderedDelivery = orderedDelivery;
}

bool QoSCube::isPartialDelivery() const {
	return partialDelivery;
}

void QoSCube::setPartialDelivery(bool partialDelivery) {
	this->partialDelivery = partialDelivery;
}

unsigned int QoSCube::getPeakBandwidthDuration() const {
	return peakBandwidthDuration;
}

void QoSCube::setPeakBandwidthDuration(unsigned int peakBandwidthDuration) {
	this->peakBandwidthDuration = peakBandwidthDuration;
}

unsigned int QoSCube::getPeakSduBandwidthDuration() const {
	return peakSDUBandwidthDuration;
}

void QoSCube::setPeakSduBandwidthDuration(
		unsigned int peakSduBandwidthDuration) {
	this->peakSDUBandwidthDuration = peakSduBandwidthDuration;
}

double QoSCube::getUndetectedBitErrorRate() const {
	return undetectedBitErrorRate;
}

void QoSCube::setUndetectedBitErrorRate(double undetectedBitErrorRate) {
	this->undetectedBitErrorRate = undetectedBitErrorRate;
}

const std::string QoSCube::toString() {
        std::stringstream ss;
        ss<<"Name: "<<name<<"; Id: "<<id;
        ss<<"; Jitter: "<<jitter<<"; Delay: "<<delay<<std::endl;
        ss<<"In oder delivery: "<<orderedDelivery;
        ss<<"; Partial delivery allowed: "<<partialDelivery<<std::endl;
        ss<<"Max allowed gap between SDUs: "<<maxAllowableGap;
        ss<<"; Undetected bit error rate: "<<undetectedBitErrorRate<<std::endl;
        ss<<"Average bandwidth (bytes/s): "<<averageBandwidth;
        ss<<"; Average SDU bandwidth (bytes/s): "<<averageSDUBandwidth<<std::endl;
        ss<<"Peak bandwidth duration (ms): "<<peakBandwidthDuration;
        ss<<"; Peak SDU bandwidth duration (ms): "<<peakSDUBandwidthDuration;
        return ss.str();
}

/* CLASS DIF PROPERTIES */
DIFProperties::DIFProperties(
		const ApplicationProcessNamingInformation& DIFName, int maxSDUSize) {
	this->DIFName = DIFName;
	this->maxSDUSize = maxSDUSize;
}

const ApplicationProcessNamingInformation& DIFProperties::getDifName() const {
	return this->DIFName;
}

unsigned int DIFProperties::getMaxSduSize() const {
	return maxSDUSize;
}

const std::list<QoSCube>& DIFProperties::getQoSCubes() const {
	return qosCubes;
}

void DIFProperties::addQoSCube(const QoSCube& qosCube) {
	this->qosCubes.push_back(qosCube);
}

void DIFProperties::removeQoSCube(const QoSCube& qosCube) {
	this->qosCubes.remove(qosCube);
}

/* CLASS BASE RESPONSE EVENT */
BaseResponseEvent::BaseResponseEvent(
                        int result,
                        IPCEventType eventType,
                        unsigned int sequenceNumber) :
                              IPCEvent(eventType,
                                             sequenceNumber){
        this->result = result;
}


int BaseResponseEvent::getResult() const {
        return result;
}

/* CLASS FLOW REQUEST EVENT */
FlowRequestEvent::FlowRequestEvent(
		const FlowSpecification& flowSpecification,
		bool localRequest,
		const ApplicationProcessNamingInformation& localApplicationName,
		const ApplicationProcessNamingInformation& remoteApplicationName,
		int flowRequestorIpcProcessId,
		unsigned int sequenceNumber):
				IPCEvent(FLOW_ALLOCATION_REQUESTED_EVENT,
						sequenceNumber) {
	this->flowSpecification = flowSpecification;
	this->localRequest = localRequest;
	this->localApplicationName = localApplicationName;
	this->remoteApplicationName = remoteApplicationName;
	this->flowRequestorIpcProcessId = flowRequestorIpcProcessId;
	this->portId = 0;
	this->ipcProcessId = 0;
}

FlowRequestEvent::FlowRequestEvent(int portId,
		const FlowSpecification& flowSpecification,
		bool localRequest,
		const ApplicationProcessNamingInformation& localApplicationName,
		const ApplicationProcessNamingInformation& remoteApplicationName,
		const ApplicationProcessNamingInformation& DIFName,
		unsigned short ipcProcessId,
		unsigned int sequenceNumber) :
		IPCEvent(FLOW_ALLOCATION_REQUESTED_EVENT,
				sequenceNumber) {
	this->flowSpecification = flowSpecification;
	this->localRequest = localRequest;
	this->localApplicationName = localApplicationName;
	this->remoteApplicationName = remoteApplicationName;
	this->DIFName = DIFName;
	this->flowRequestorIpcProcessId = ipcProcessId;
	this->portId = portId;
	this->ipcProcessId = ipcProcessId;
}

void FlowRequestEvent::setPortId(int portId){
	this->portId = portId;
}

void FlowRequestEvent::setDIFName(
		const ApplicationProcessNamingInformation& difName){
	this->DIFName = difName;
}

int FlowRequestEvent::getPortId() const {
	return portId;
}

bool FlowRequestEvent::isLocalRequest() const{
	return localRequest;
}

const FlowSpecification& FlowRequestEvent::getFlowSpecification() const {
	return flowSpecification;
}

const ApplicationProcessNamingInformation&
	FlowRequestEvent::getDIFName() const {
	return DIFName;
}

const ApplicationProcessNamingInformation&
	FlowRequestEvent::getLocalApplicationName() const {
	return localApplicationName;
}

const ApplicationProcessNamingInformation&
	FlowRequestEvent::getRemoteApplicationName() const {
	return remoteApplicationName;
}

int FlowRequestEvent::getFlowRequestorIPCProcessId() const {
        return flowRequestorIpcProcessId;
}

unsigned short FlowRequestEvent::getIPCProcessId() const {
        return ipcProcessId;
}

/* CLASS FLOW DEALLOCATE REQUEST EVENT */
FlowDeallocateRequestEvent::FlowDeallocateRequestEvent(int portId,
			const ApplicationProcessNamingInformation& appName,
			unsigned int sequenceNumber):
						IPCEvent(FLOW_DEALLOCATION_REQUESTED_EVENT,
								sequenceNumber){
	this->portId = portId;
	this->applicationName = appName;
}

FlowDeallocateRequestEvent::FlowDeallocateRequestEvent(int portId,
		unsigned int sequenceNumber):
			IPCEvent(FLOW_DEALLOCATION_REQUESTED_EVENT,
					sequenceNumber){
	this->portId = portId;
}

int FlowDeallocateRequestEvent::getPortId() const{
	return portId;
}

const ApplicationProcessNamingInformation&
	FlowDeallocateRequestEvent::getApplicationName() const{
	return applicationName;
}

/* CLASS FLOW DEALLOCATED EVENT */
FlowDeallocatedEvent::FlowDeallocatedEvent(
		int portId, int code) :
				IPCEvent(FLOW_DEALLOCATED_EVENT, 0) {
	this->portId = portId;
	this->code = code;
}

int FlowDeallocatedEvent::getPortId() const {
	return portId;
}

int FlowDeallocatedEvent::getCode() const{
	return code;
}

/* CLASS APPLICATION REGISTRATION INFORMATION */
ApplicationRegistrationInformation::ApplicationRegistrationInformation(){
	applicationRegistrationType = APPLICATION_REGISTRATION_ANY_DIF;
	ipcProcessId = 0;
}

ApplicationRegistrationInformation::ApplicationRegistrationInformation(
		ApplicationRegistrationType applicationRegistrationType){
	this->applicationRegistrationType = applicationRegistrationType;
	ipcProcessId = 0;
}

ApplicationRegistrationType
ApplicationRegistrationInformation::getRegistrationType() const{
	return applicationRegistrationType;
}

const ApplicationProcessNamingInformation &
ApplicationRegistrationInformation::getDIFName() const{
	return difName;
}

void ApplicationRegistrationInformation::setDIFName(
		const ApplicationProcessNamingInformation& difName){
	this->difName = difName;
}

const ApplicationProcessNamingInformation&
        ApplicationRegistrationInformation::getApplicationName() const {
        return appName;
}

void ApplicationRegistrationInformation::setApplicationName(
                const ApplicationProcessNamingInformation& appName) {
        this->appName = appName;
}

unsigned short ApplicationRegistrationInformation::getIpcProcessId() const {
        return ipcProcessId;
}

void ApplicationRegistrationInformation::setIpcProcessId(
                unsigned short ipcProcessId) {
        this->ipcProcessId = ipcProcessId;
}

const std::string ApplicationRegistrationInformation::toString(){
        std::stringstream ss;

        ss<<"Application name: "<<appName.toString()<<std::endl;
        ss<<"DIF name: "<<difName.getProcessName();
        ss<<"; IPC Process id: "<<ipcProcessId;

        return ss.str();
}

/* CLASS APPLICATION REGISTRATION REQUEST */
ApplicationRegistrationRequestEvent::ApplicationRegistrationRequestEvent(
	const ApplicationRegistrationInformation&
	applicationRegistrationInformation, unsigned int sequenceNumber) :
		IPCEvent(APPLICATION_REGISTRATION_REQUEST_EVENT,
				sequenceNumber) {
	this->applicationRegistrationInformation =
			applicationRegistrationInformation;
}

const ApplicationRegistrationInformation&
ApplicationRegistrationRequestEvent::getApplicationRegistrationInformation()
const {
	return applicationRegistrationInformation;
}

/* CLASS BASE APPLICATION REGISTRATION EVENT */
BaseApplicationRegistrationEvent::BaseApplicationRegistrationEvent(
                        const ApplicationProcessNamingInformation& appName,
                        const ApplicationProcessNamingInformation& DIFName,
                        IPCEventType eventType,
                        unsigned int sequenceNumber):
                                IPCEvent(eventType, sequenceNumber) {
        this->applicationName = appName;
        this->DIFName = DIFName;
}

BaseApplicationRegistrationEvent::BaseApplicationRegistrationEvent(
                        const ApplicationProcessNamingInformation& appName,
                        IPCEventType eventType,
                        unsigned int sequenceNumber):
                                IPCEvent(eventType, sequenceNumber) {
        this->applicationName = appName;
}

const ApplicationProcessNamingInformation&
BaseApplicationRegistrationEvent::getApplicationName() const {
        return applicationName;
}

const ApplicationProcessNamingInformation&
BaseApplicationRegistrationEvent::getDIFName() const {
        return DIFName;
}

/* CLASS APPLICATION UNREGISTRATION REQUEST EVENT */
ApplicationUnregistrationRequestEvent::ApplicationUnregistrationRequestEvent(
		const ApplicationProcessNamingInformation& appName,
		const ApplicationProcessNamingInformation& DIFName,
		unsigned int sequenceNumber) :
                BaseApplicationRegistrationEvent(
                                appName, DIFName,
                                APPLICATION_UNREGISTRATION_REQUEST_EVENT,
				sequenceNumber) {
}

/* CLASS BASE APPLICATION RESPONSE EVENT */
BaseApplicationRegistrationResponseEvent::
        BaseApplicationRegistrationResponseEvent(
                const ApplicationProcessNamingInformation& appName,
                const ApplicationProcessNamingInformation& DIFName,
                int result,
                IPCEventType eventType,
                unsigned int sequenceNumber) :
                BaseApplicationRegistrationEvent (
                                appName, DIFName,
                                eventType, sequenceNumber){
        this->result = result;
}

BaseApplicationRegistrationResponseEvent::
        BaseApplicationRegistrationResponseEvent(
                const ApplicationProcessNamingInformation& appName,
                int result,
                IPCEventType eventType,
                unsigned int sequenceNumber) :
                BaseApplicationRegistrationEvent (
                                appName,
                                eventType, sequenceNumber){
        this->result = result;
}

int BaseApplicationRegistrationResponseEvent::getResult() const{
        return result;
}

/* CLASS REGISTER APPLICATION RESPONSE EVENT */
RegisterApplicationResponseEvent::RegisterApplicationResponseEvent(
                        const ApplicationProcessNamingInformation& appName,
                        const ApplicationProcessNamingInformation& difName,
                        int result,
                        unsigned int sequenceNumber):
                BaseApplicationRegistrationResponseEvent(
                                       appName, difName, result,
                                       REGISTER_APPLICATION_RESPONSE_EVENT,
                                       sequenceNumber){
}

/* CLASS UNREGISTER APPLICATION RESPONSE EVENT */
UnregisterApplicationResponseEvent::UnregisterApplicationResponseEvent(
                        const ApplicationProcessNamingInformation& appName,
                        int result,
                        unsigned int sequenceNumber):
                BaseApplicationRegistrationResponseEvent(
                                       appName, result,
                                       UNREGISTER_APPLICATION_RESPONSE_EVENT,
                                       sequenceNumber){
}

/* CLASS ALLOCATE FLOW RESPONSE EVENT */
AllocateFlowResponseEvent::AllocateFlowResponseEvent(
                int result,
                bool notifysource,
                int flowAcceptorIpcProcessId,
                unsigned int sequenceNumber) :
                BaseResponseEvent(result,
                                 ALLOCATE_FLOW_RESPONSE_EVENT,
                                 sequenceNumber) {
        this->notifySource = notifySource;
        this->flowAcceptorIpcProcessId = flowAcceptorIpcProcessId;
}

bool AllocateFlowResponseEvent::isNotifySource() const {
        return notifySource;
}

int AllocateFlowResponseEvent::getFlowAcceptorIpcProcessId() const {
        return flowAcceptorIpcProcessId;
}

/* CLASS OS PROCESS FINALIZED EVENT */
OSProcessFinalizedEvent::OSProcessFinalizedEvent(
		const ApplicationProcessNamingInformation& appName,
		unsigned int ipcProcessId,
		unsigned int sequenceNumber) :
		IPCEvent(OS_PROCESS_FINALIZED,
				sequenceNumber) {
	this->applicationName = appName;
	this->ipcProcessId = ipcProcessId;
}

const ApplicationProcessNamingInformation&
OSProcessFinalizedEvent::getApplicationName() const {
	return applicationName;
}

unsigned int OSProcessFinalizedEvent::getIPCProcessId() const {
	return ipcProcessId;
}


/* CLASS IPC EVENT PRODUCER */

/* Auxiliar function called in case of using the stubbed version of the API */
IPCEvent * getIPCEvent(){
	ApplicationProcessNamingInformation sourceName;
	sourceName.setProcessName("/apps/source");
	sourceName.setProcessInstance("12");
	sourceName.setEntityName("database");
	sourceName.setEntityInstance("12");

	ApplicationProcessNamingInformation destName;
	destName.setProcessName("/apps/dest");
	destName.setProcessInstance("12345");
	destName.setEntityName("printer");
	destName.setEntityInstance("12623456");

	FlowSpecification flowSpec;

	FlowRequestEvent * event = new
			FlowRequestEvent(flowSpec, true, sourceName,
			                destName, 0, 24);

	return event;
}

IPCEvent * IPCEventProducer::eventPoll() {
#if STUB_API
	return getIPCEvent();
#else
	return rinaManager->getEventQueue()->poll();
#endif
}

IPCEvent * IPCEventProducer::eventWait() {
#if STUB_API
	return getIPCEvent();
#else
	return rinaManager->getEventQueue()->take();
#endif
}

IPCEvent * IPCEventProducer::eventTimedWait(
		int seconds, int nanoseconds){
#if STUB_API
	return getIPCEvent();
#else
	return rinaManager->getEventQueue()->timedtake(seconds, nanoseconds);
#endif
}

Singleton<IPCEventProducer> ipcEventProducer;

/* CLASS IPC EXCEPTION */

IPCException::IPCException(const std::string& description) :
		Exception(description) {
}

const std::string IPCException::operation_not_implemented_error =
		"This operation is not yet implemented";

/* CLASS PARAMETER */
Parameter::Parameter(){
}

Parameter::Parameter(const std::string & name, const std::string & value){
	this->name = name;
	this->value = value;
}

bool Parameter::operator==(const Parameter &other) const {
	if (this->name.compare(other.getName()) == 0 &&
			this->value.compare(other.getValue()) == 0)
		return true;

	return false;
}

bool Parameter::operator!=(const Parameter &other) const {
	return !(*this == other);
}

const std::string& Parameter::getName() const {
	return name;
}

void Parameter::setName(const std::string& name) {
	this->name = name;
}

const std::string& Parameter::getValue() const {
	return value;
}

void Parameter::setValue(const std::string& value) {
	this->value = value;
}

/* CLASS DATA TRANSFER CONSTANTS */
DataTransferConstants::DataTransferConstants() {
        qosIdLenght = 0;
        portIdLength = 0;
        cepIdLength = 0;
        sequenceNumberLength = 0;
        addressLength = 0;
        lengthLength = 0;
        maxPDUSize = 0;
        DIFIntegrity = false;
        maxPDULifetime = 0;
}

unsigned short DataTransferConstants::getAddressLength() const {
        return addressLength;
}

void DataTransferConstants::setAddressLength(unsigned short addressLength) {
        this->addressLength = addressLength;
}

unsigned short DataTransferConstants::getCepIdLength() const {
        return cepIdLength;
}

void DataTransferConstants::setCepIdLength(unsigned short cepIdLength) {
        this->cepIdLength = cepIdLength;
}

bool DataTransferConstants::isDifIntegrity() const {
        return DIFIntegrity;
}

void DataTransferConstants::setDifIntegrity(bool difIntegrity) {
        DIFIntegrity = difIntegrity;
}

unsigned short DataTransferConstants::getLengthLength() const {
        return lengthLength;
}

void DataTransferConstants::setLengthLength(unsigned short lengthLength) {
        this->lengthLength = lengthLength;
}

unsigned int DataTransferConstants::getMaxPduLifetime() const {
        return maxPDULifetime;
}

void DataTransferConstants::setMaxPduLifetime(unsigned int maxPduLifetime) {
        maxPDULifetime = maxPduLifetime;
}

unsigned int DataTransferConstants::getMaxPduSize() const {
        return maxPDUSize;
}

void DataTransferConstants::setMaxPduSize(unsigned int maxPduSize) {
        maxPDUSize = maxPduSize;
}

unsigned short DataTransferConstants::getPortIdLength() const {
        return portIdLength;
}

void DataTransferConstants::setPortIdLength(unsigned short portIdLength) {
        this->portIdLength = portIdLength;
}

unsigned short DataTransferConstants::getQosIdLenght() const {
        return qosIdLenght;
}

void DataTransferConstants::setQosIdLenght(unsigned short qosIdLenght) {
        this->qosIdLenght = qosIdLenght;
}

unsigned short DataTransferConstants::getSequenceNumberLength() const {
        return sequenceNumberLength;
}

void DataTransferConstants::setSequenceNumberLength(
                unsigned short sequenceNumberLength) {
        this->sequenceNumberLength = sequenceNumberLength;
}

bool DataTransferConstants::isInitialized() {
        if (qosIdLenght == 0 || addressLength == 0 || cepIdLength == 0 ||
            qosIdLenght == 0 || lengthLength == 0 ){
                return false;
        }

        return true;
}

const std::string DataTransferConstants::toString(){
        std::stringstream ss;

        ss<<"Address length (bytes): "<<addressLength;
        ss<<"; CEP-id length (bytes): "<<cepIdLength;
        ss<<"; Length length (bytes): "<<lengthLength<<std::endl;
        ss<<"Port-id length (bytes): "<<portIdLength;
        ss<<"; Qos-id length (bytes): "<<qosIdLenght;
        ss<<"; Seq number length(bytes): "<<sequenceNumberLength<<std::endl;
        ss<<"Max PDU lifetime: "<<maxPDULifetime;
        ss<<"; Max PDU size: "<<maxPDUSize;
        ss<<"; Integrity?: "<<DIFIntegrity;
        ss<<"; Initialized?: "<<isInitialized();

        return ss.str();
}

/* CLASS POLICY PAREMETER */
PolicyParameter::PolicyParameter(){
}

PolicyParameter::PolicyParameter(const std::string& name,
                const std::string& value){
        this->name = name;
        this->value = value;
}

bool PolicyParameter::operator==(const PolicyParameter &other) const {
        return other.getName().compare(name) == 0;
}

bool PolicyParameter::operator!=(const PolicyParameter &other) const {
        return !(*this == other);
}

const std::string& PolicyParameter::getName() const {
        return name;
}

void PolicyParameter::setName(const std::string& name) {
        this->name = name;
}

const std::string& PolicyParameter::getValue() const {
        return value;
}

void PolicyParameter::setValue(const std::string& value) {
        this->value = value;
}

/* CLASS POLICY CONFIGURATION */
PolicyConfig::PolicyConfig() {
        name = RINA_DEFAULT_POLICY_NAME;
        version = RINA_DEFAULT_POLICY_VERSION;
}

PolicyConfig::PolicyConfig(const std::string& name,
                const std::string& version) {
        this->name = name;
        this->version = version;
}

bool PolicyConfig::operator==(const PolicyConfig &other) const {
        return other.getName().compare(name) == 0 &&
                        other.getVersion().compare(version) == 0;
}

bool PolicyConfig::operator!=(const PolicyConfig &other) const {
        return !(*this == other);
}

const std::string& PolicyConfig::getName() const {
        return name;
}

void PolicyConfig::setName(const std::string& name) {
        this->name = name;
}

/*const std::list<PolicyParameter>&
PolicyConfig::getParameters() const {
        return parameters;
}

void PolicyConfig::setParameters(
                const std::list<PolicyParameter>& parameters) {
        this->parameters = parameters;
}

void PolicyConfig::addParameter(const PolicyParameter& paremeter) {
        parameters.push_back(paremeter);
}*/

const std::string& PolicyConfig::getVersion() const {
        return version;
}

void PolicyConfig::setVersion(const std::string& version) {
        this->version = version;
}

/* CLASS LinkStateRouting Configuraiton */
LinkStateRoutingConfiguration::LinkStateRoutingConfiguration()
{
	waitUntilReadCDAP = WAIT_UNTIL_READ_CDAP_DEFAULT;
	waitUntilError = WAIT_UNTIL_ERROR_DEFAULT;
	waitUntilPDUFTComputation = WAIT_UNTIL_PDUFT_COMPUTATION_DEFAULT;
	waitUntilFSODBPropagation = WAIT_UNTIL_FSODB_PROPAGATION_DEFAULT;
	waitUntilAgeIncrement = WAIT_UNTIL_AGE_INCREMENT_DEFAULT;
	objectMaximumAge = PULSES_UNTIL_FSO_EXPIRATION_DEFAULT;
	routingAlgorithm = DEFAULT_ROUTING_ALGORITHM;
}

const std::string LinkStateRoutingConfiguration::DEFAULT_ROUTING_ALGORITHM =
                "Dijkstra";

const std::string LinkStateRoutingConfiguration::toString() {
    std::stringstream ss;

    ss<<"Timer until send a Read CDAP message (ms): " << waitUntilReadCDAP <<std::endl;
    ss<<"Timer until send CDAP error (ms): "<<waitUntilError<<std::endl;
    ss<<"Timer between PDU forwarding table Computation (ms): "<<waitUntilPDUFTComputation<<std::endl;
    ss<<"Timer between FlowStateDataBase propagation (ms): "<<waitUntilFSODBPropagation<<std::endl;
    ss<<"Timer between age incrementation pulses (ms): "<<waitUntilAgeIncrement<<std::endl;
    ss<<"Number of pulses until FSO expiration: "<<objectMaximumAge<<std::endl;

    return ss.str();
}


int LinkStateRoutingConfiguration::getWaitUntilAgeIncrement() const {
	return waitUntilAgeIncrement;
}

void LinkStateRoutingConfiguration::setWaitUntilAgeIncrement(int waitUntilAgeIncrement) {
	this->waitUntilAgeIncrement = waitUntilAgeIncrement;
}

int LinkStateRoutingConfiguration::getWaitUntilError() const {
	return waitUntilError;
}

void LinkStateRoutingConfiguration::setWaitUntilError(int waitUntilError) {
	this->waitUntilError = waitUntilError;
}

int LinkStateRoutingConfiguration::getWaitUntilFSODBPropagation() const {
	return waitUntilFSODBPropagation;
}

void LinkStateRoutingConfiguration::setWaitUntilFSODBPropagation(int waitUntilFsodbPropagation) {
	waitUntilFSODBPropagation = waitUntilFsodbPropagation;
}

int LinkStateRoutingConfiguration::getWaitUntilPDUFTComputation() const {
	return waitUntilPDUFTComputation;
}

void LinkStateRoutingConfiguration::setWaitUntilPDUFTComputation(int waitUntilPduftComputation) {
	waitUntilPDUFTComputation = waitUntilPduftComputation;
}

int LinkStateRoutingConfiguration::getWaitUntilReadCDAP() const {
	return waitUntilReadCDAP;
}

void LinkStateRoutingConfiguration::setWaitUntilReadCDAP(int waitUntilReadCdap) {
	waitUntilReadCDAP = waitUntilReadCdap;
}

int LinkStateRoutingConfiguration::getObjectMaximumAge() const {
	return objectMaximumAge;
}

void LinkStateRoutingConfiguration::setObjectMaximumAge(const int objectMaximumAge) {
	this->objectMaximumAge = objectMaximumAge;
}

const std::string& LinkStateRoutingConfiguration::getRoutingAlgorithm() const {
        return routingAlgorithm;
}

void LinkStateRoutingConfiguration::setRoutingAlgorithm(
                const std::string& routingAlgorithm) {
        this->routingAlgorithm = routingAlgorithm;
}

/* CLAS PDUFTableGeneratorConfiguration */
PDUFTableGeneratorConfiguration::PDUFTableGeneratorConfiguration(){
        setPduFtGeneratorPolicy(PolicyConfig("LinkState",
                        RINA_DEFAULT_POLICY_VERSION));
}

PDUFTableGeneratorConfiguration::PDUFTableGeneratorConfiguration(
                const PolicyConfig& pduFTGeneratorPolicy) {
        setPduFtGeneratorPolicy(pduFTGeneratorPolicy);
}

const LinkStateRoutingConfiguration&
PDUFTableGeneratorConfiguration::getLinkStateRoutingConfiguration() const {
        return linkStateRoutingConfiguration;
}

void PDUFTableGeneratorConfiguration::setLinkStateRoutingConfiguration(
                const LinkStateRoutingConfiguration& linkStateRoutingConfiguration){
        this->linkStateRoutingConfiguration =
                        linkStateRoutingConfiguration;
}

const PolicyConfig&
PDUFTableGeneratorConfiguration::getPduFtGeneratorPolicy() const {
        return pduFTGeneratorPolicy;
}

void PDUFTableGeneratorConfiguration::setPduFtGeneratorPolicy(
                const PolicyConfig& pduFtGeneratorPolicy){
        this->pduFTGeneratorPolicy = pduFtGeneratorPolicy;
}

/* CLASS DIF INFORMATION */
const ApplicationProcessNamingInformation& DIFInformation::getDifName()
		const {
	return difName;
}

void DIFInformation::setDifName(
		const ApplicationProcessNamingInformation& difName) {
	this->difName = difName;
}

const std::string& DIFInformation::getDifType() const {
	return difType;
}

void DIFInformation::setDifType(const std::string& difType) {
	this->difType = difType;
}

const DIFConfiguration& DIFInformation::getDifConfiguration()
		const {
	return difConfiguration;
}

void DIFInformation::setDifConfiguration(
		const DIFConfiguration& difConfiguration) {
	this->difConfiguration = difConfiguration;
}

/* CLASS DIF CONFIGURATION */
unsigned int DIFConfiguration::getAddress() const {
        return address;
}

void DIFConfiguration::setAddress(unsigned int address) {
        this->address = address;
}

const std::list<PolicyConfig>& DIFConfiguration::getPolicies() {
	return policies;
}

void DIFConfiguration::setPolicies(const std::list<PolicyConfig>& policies) {
	this->policies = policies;
}

void DIFConfiguration::addPolicy(const PolicyConfig& policy) {
        policies.push_back(policy);
}

const std::list<QoSCube>& DIFConfiguration::getQosCubes() const {
	return qosCubes;
}

void DIFConfiguration::setQosCubes(const std::list<QoSCube>& qosCubes) {
	this->qosCubes = qosCubes;
}

void DIFConfiguration::addQoSCube(const QoSCube& qosCube) {
        std::list<QoSCube>::const_iterator iterator;
        for (iterator = qosCubes.begin(); iterator != qosCubes.end(); ++iterator) {
            if (iterator->getId() == qosCube.getId()) {
                    return;
            }
        }

        qosCubes.push_back(qosCube);
}

const std::list<Parameter>& DIFConfiguration::getParameters() const {
	return parameters;
}

void DIFConfiguration::setParameters(const std::list<Parameter>& parameters) {
	this->parameters = parameters;
}

void DIFConfiguration::addParameter(const Parameter& parameter){
	parameters.push_back(parameter);
}

const DataTransferConstants&
DIFConfiguration::getDataTransferConstants() const {
        return dataTransferConstants;
}

void DIFConfiguration::setDataTransferConstants(
                const DataTransferConstants& dataTransferConstants) {
        this->dataTransferConstants = dataTransferConstants;
}

void DIFConfiguration::setPDUFTableGeneratorConfiguration(const PDUFTableGeneratorConfiguration& pdufTableGeneratorConfiguration)
{
	this->pdufTableGeneratorConfiguration = pdufTableGeneratorConfiguration;
}

const PDUFTableGeneratorConfiguration& DIFConfiguration::getPDUFTableGeneratorConfiguration() const
{
	return pdufTableGeneratorConfiguration;
}

/* CLASS NEIGHBOR */
Neighbor::Neighbor() {
        address = false;
        averageRTTInMs = 0;
        lastHeardFromTimeInMs = 0;
        enrolled = false;
        underlyingPortId = 0;
        numberOfEnrollmentAttempts = 0;
}

bool Neighbor::operator==(const Neighbor &other) const{
        return name == other.getName();
}

bool Neighbor::operator!=(const Neighbor &other) const{
        return !(*this == other);
}

const ApplicationProcessNamingInformation&
Neighbor::getName() const {
        return name;
}

void Neighbor::setName(
        const ApplicationProcessNamingInformation& name) {
        this->name = name;
}

const ApplicationProcessNamingInformation&
Neighbor::getSupportingDifName() const {
        return supportingDifName;
}

void Neighbor::setSupportingDifName(
        const ApplicationProcessNamingInformation& supportingDifName) {
        this->supportingDifName = supportingDifName;
}

const std::list<ApplicationProcessNamingInformation>&
Neighbor::getSupportingDifs() {
        return supportingDifs;
}

void Neighbor::setSupportingDifs(
        const std::list<ApplicationProcessNamingInformation>& supportingDifs) {
        this->supportingDifs = supportingDifs;
}

void Neighbor::addSupoprtingDif(
                const ApplicationProcessNamingInformation& supportingDif) {
        supportingDifs.push_back(supportingDif);
}

unsigned int Neighbor::getAddress() const {
        return address;
}

void Neighbor::setAddress(unsigned int address) {
        this->address = address;
}

unsigned int Neighbor::getAverageRttInMs() const {
        return averageRTTInMs;
}

void Neighbor::setAverageRttInMs(unsigned int averageRttInMs) {
        averageRTTInMs = averageRttInMs;
}

bool Neighbor::isEnrolled() const {
        return enrolled;
}

void Neighbor::setEnrolled(bool enrolled){
        this->enrolled = enrolled;
}

long long Neighbor::getLastHeardFromTimeInMs() const {
        return lastHeardFromTimeInMs;
}

void Neighbor::setLastHeardFromTimeInMs(long long lastHeardFromTimeInMs) {
        this->lastHeardFromTimeInMs = lastHeardFromTimeInMs;
}

int Neighbor::getUnderlyingPortId() const {
        return underlyingPortId;
}

void Neighbor::setUnderlyingPortId(int underlyingPortId) {
        this->underlyingPortId = underlyingPortId;
}

unsigned int Neighbor::getNumberOfEnrollmentAttempts() const {
        return numberOfEnrollmentAttempts;
}

void Neighbor::setNumberOfEnrollmentAttempts(
                unsigned int numberOfEnrollmentAttempts) {
        this->numberOfEnrollmentAttempts = numberOfEnrollmentAttempts;
}

const std::string Neighbor::toString(){
        std::stringstream ss;

        ss<<"Address: "<<address;
        ss<<"; Average RTT(ms): "<<averageRTTInMs;
        ss<<"; Is enrolled: "<<enrolled<<std::endl;
        ss<<"Name: "<<name.toString()<<std::endl;
        ss<<"Supporting DIF in common: "<<supportingDifName.getProcessName();
        ss<<"; N-1 port-id: "<<underlyingPortId<<std::endl;
        ss<<"List of supporting DIFs: ";
        for (std::list<ApplicationProcessNamingInformation>::iterator it = supportingDifs.begin();
                        it != supportingDifs.end(); it++)
           ss<< it->getProcessName() << "; ";
        ss<<std::endl;
        ss<<"Last heard from time (ms): "<<lastHeardFromTimeInMs;
        ss<<"; Number of enrollment attempts: "<<numberOfEnrollmentAttempts;

        return ss.str();
}

/* CLAS RIBOBJECT */
RIBObject::RIBObject(){
	instance = generateObjectInstance();
}

RIBObject::RIBObject(
		std::string clazz, std::string name,
		long long instance, RIBObjectValue value){
	this->clazz = clazz;
	this->name = name;
	this->value = value;
	this->instance = instance;
}

bool RIBObject::operator==(const RIBObject &other) const{
	if (clazz.compare(other.getClazz()) != 0) {
		return false;
	}

	if (name.compare(other.getName()) != 0) {
		return false;
	}

	return instance == other.getInstance();
}

bool RIBObject::operator!=(const RIBObject &other) const{
	return !(*this == other);
}

unsigned long RIBObject::generateObjectInstance(){
	//TODO generate instance properly
	return 0;
}

const std::string& RIBObject::getClazz() const {
	return clazz;
}

void RIBObject::setClazz(const std::string& clazz) {
	this->clazz = clazz;
}

unsigned long RIBObject::getInstance() const {
	return instance;
}

void RIBObject::setInstance(unsigned long instance) {
	this->instance = instance;
}

const std::string& RIBObject::getName() const {
	return name;
}

void RIBObject::setName(const std::string& name) {
	this->name = name;
}

RIBObjectValue RIBObject::getValue() const {
	return value;
}

void RIBObject::setValue(RIBObjectValue value) {
	this->value = value;
}


const std::string& RIBObject::getDisplayableValue() const {
        return displayableValue;
}

void RIBObject::setDisplayableValue(const std::string& displayableValue) {
        this->displayableValue = displayableValue;
}


/* INITIALIZATION OPERATIONS */

bool librinaInitialized = false;
Lockable librinaInitializationLock;

void initialize(unsigned int localPort, const std::string& logLevel,
                const std::string& pathToLogFile)
        throw(InitializationException) {

        librinaInitializationLock.lock();
        if (librinaInitialized) {
                librinaInitializationLock.unlock();
                throw InitializationException("Librina already initialized");
        }

	setNetlinkPortId(localPort);
	setLogLevel(logLevel);
	if (setLogFile(pathToLogFile) != 0) {
	        LOG_WARN("Error setting log file, using stdout only");
	}
	rinaManager->getNetlinkManager();

	librinaInitialized = true;
	librinaInitializationLock.unlock();
}

void initialize(const std::string& logLevel,
                const std::string& pathToLogFile)
throw (InitializationException){

        librinaInitializationLock.lock();
        if (librinaInitialized) {
                librinaInitializationLock.unlock();
                throw InitializationException("Librina already initialized");
        }

        setLogLevel(logLevel);
        if (setLogFile(pathToLogFile) != 0) {
                LOG_WARN("Error setting log file, using stdout only");
        }

        rinaManager->getNetlinkManager();

        librinaInitialized = true;
        librinaInitializationLock.unlock();
}

}
