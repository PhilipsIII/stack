#
# Makefile for RINA
#
# Written by Francesco Salvestrini <f.salvestrini@nextworks.it>
#

ccflags-y += -Wtype-limits

obj-$(CONFIG_RINA) +=				\
	utils.o debug.o				\
	rds/					\
	core.o personality.o			\
	rnl-utils.o rnl-workarounds.o rnl.o	\
	buffer.o qos.o pci.o pdu.o sdu.o du.o	\
	pdu-ser.o serdes.o ipcp-utils.o         \
	connection.o common.o policies.o        \
	dtcp-utils.o                            \

obj-y +=					\
	syscalls.o

obj-$(CONFIG_RINA_PERSONALITY_DEFAULT) +=	\
	rina-personality-default.o

rina-personality-default-y :=					\
	du-protection.o						\
	ipcp-factories.o ipcp-instances.o			\
	cidm.o dt.o dt-utils.o dtcp.o dtp.o efcp-utils.o efcp.o	\
	pft.o rmt.o						\
	pim.o pidm.o kfa-utils.o kfa.o				\
	kipcm-utils.o kipcm.o					\
	default.o

ifeq  ($(CONFIG_RINA_PERSONALITY_DEFAULT),m)
rina-personality-default-y +=			\
	 utils-workarounds.o
endif

obj-$(CONFIG_VMPI) += vmpi/
obj-$(CONFIG_RINA) += ipcps/
obj-$(CONFIG_RINA) += rinarp/
