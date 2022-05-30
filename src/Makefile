#
# OMNeT++/OMNEST Makefile for $(LIB_PREFIX)plexe
#
# This file was generated with the command:
#  opp_makemake -f --deep --no-deep-includes --make-so -I . -o plexe -O out -p PLEXE -I../../veins-veins-5.1/src -L../../veins-veins-5.1/src -lveins$(D)
#

# Name of target to be created (-o option)
TARGET = $(LIB_PREFIX)plexe$(D)$(SHARED_LIB_SUFFIX)
TARGET_DIR = .

# C++ include paths (with -I)
INCLUDE_PATH = -I. -I../../veins-veins-5.1/src

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = $(LDFLAG_LIBPATH)../../veins-veins-5.1/src  -lveins$(D)

# Output directory
PROJECT_OUTPUT_DIR = ../out
PROJECTRELATIVE_PATH = src
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc, .msg and .sm files
OBJS = \
    $O/plexe/PlexeManager.o \
    $O/plexe/apps/BaseApp.o \
    $O/plexe/apps/GeneralPlatooningApp.o \
    $O/plexe/apps/SimplePlatooningApp.o \
    $O/plexe/driver/Veins11pRadioDriver.o \
    $O/plexe/maneuver/JoinAtBack.o \
    $O/plexe/maneuver/JoinManeuver.o \
    $O/plexe/maneuver/Maneuver.o \
    $O/plexe/maneuver/MergeAtBack.o \
    $O/plexe/maneuver/ExitAtBack.o \
    $O/plexe/mobility/CommandInterface.o \
    $O/plexe/mobility/SumoTrafficManager.o \
    $O/plexe/mobility/TestTrafficManager.o \
    $O/plexe/mobility/TraCIBaseTrafficManager.o \
    $O/plexe/protocols/BaseProtocol.o \
    $O/plexe/protocols/HumanInterferingProtocol.o \
    $O/plexe/protocols/SimplePlatooningBeaconing.o \
    $O/plexe/protocols/SlottedBeaconing.o \
    $O/plexe/scenarios/AccelerateAndBrakeScenario.o \
    $O/plexe/scenarios/AutoLaneChangeScenario.o \
    $O/plexe/scenarios/BaseScenario.o \
    $O/plexe/scenarios/BrakingScenario.o \
    $O/plexe/scenarios/JoinManeuverScenario.o \
    $O/plexe/scenarios/MergeManeuverScenario.o \
    $O/plexe/scenarios/SimpleScenario.o \
    $O/plexe/scenarios/SinusoidalScenario.o \
    $O/plexe/traffic/JoinTrafficManager.o \
    $O/plexe/traffic/PlatoonsPlusHumanTraffic.o \
    $O/plexe/traffic/PlatoonsTrafficManager.o \
    $O/plexe/traffic/RingTrafficManager.o \
    $O/plexe/utilities/BasePositionHelper.o \
    $O/plexe/utilities/DynamicPositionManager.o \
    $O/plexe/utilities/PositionHelper.o \
    $O/plexe/messages/InterferingBeacon_m.o \
    $O/plexe/messages/JoinFormation_m.o \
    $O/plexe/messages/JoinFormationAck_m.o \
    $O/plexe/messages/JoinPlatoonRequest_m.o \
    $O/plexe/messages/JoinPlatoonResponse_m.o \
    $O/plexe/messages/ManeuverMessage_m.o \
    $O/plexe/messages/MergePlatoonRequest_m.o \
    $O/plexe/messages/MoveToPosition_m.o \
    $O/plexe/messages/MoveToPositionAck_m.o \
    $O/plexe/messages/PlatooningBeacon_m.o \
    $O/plexe/messages/PlexeInterfaceControlInfo_m.o \
    $O/plexe/messages/UpdatePlatoonData_m.o \
    $O/plexe/messages/UpdatePlatoonFormation_m.o \
    $O/plexe/messages/UpdatePlatoonFormationAck_m.o \
    $O/plexe/messages/ExitPlatoonRequest_m.o \
    $O/plexe/messages/ExitPlatoonResponse_m.o 
# Message files
MSGFILES = \
    plexe/messages/InterferingBeacon.msg \
    plexe/messages/JoinFormation.msg \
    plexe/messages/JoinFormationAck.msg \
    plexe/messages/JoinPlatoonRequest.msg \
    plexe/messages/JoinPlatoonResponse.msg \
    plexe/messages/ManeuverMessage.msg \
    plexe/messages/MergePlatoonRequest.msg \
    plexe/messages/MoveToPosition.msg \
    plexe/messages/MoveToPositionAck.msg \
    plexe/messages/PlatooningBeacon.msg \
    plexe/messages/PlexeInterfaceControlInfo.msg \
    plexe/messages/UpdatePlatoonData.msg \
    plexe/messages/UpdatePlatoonFormation.msg \
    plexe/messages/UpdatePlatoonFormationAck.msg \
    plexe/messages/ExitPlatoonRequest.msg \
    plexe/messages/ExitPlatoonResponse.msg

# SM files
SMFILES =

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIBS = -loppenvir$D $(KERNEL_LIBS) $(SYS_LIBS)
ifneq ($(TOOLCHAIN_NAME),clangc2)
LIBS += -Wl,-rpath,$(abspath ../../veins-veins-5.1/src)
endif

COPTS = $(CFLAGS) $(IMPORT_DEFINES) -DPLEXE_EXPORT $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH) -PPLEXE_API
SMCOPTS =

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# inserted from file 'makefrag':

#
# Copyright (C) 2017 Rudolf Hornig <rudi@omnetpp.org>
# Copyright (C) 2018-2021 Christoph Sommer <sommer@cms-labs.org>
#
# Documentation for these modules is at http://veins.car2x.org/
#
# SPDX-License-Identifier: GPL-2.0-or-later
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
#

#
# on windows, special care is needed for linking
# adapted from INET Framework (inet-4.2.1) makefrag
#
ifeq ($(PLATFORM),win32.x86_64)
  #
  # on windows we have to link with the ws2_32 (winsock2) library as it is no longer added
  # to the omnetpp system libraries by default (as of OMNeT++ 5.1)
  #
  LIBS += -lws2_32
  DEFINES += -DPLEXE_EXPORT
  ENABLE_AUTO_IMPORT=-Wl,--enable-auto-import
  LDFLAGS := $(filter-out $(ENABLE_AUTO_IMPORT), $(LDFLAGS))

  # FIX for clang not exporting typeinfo and other thunks on Windows
  ifeq ($(CC),clang)
    DEFFILE = $O/typeinfo.def
    LDFLAGS += $(DEFFILE)

.PHONY: all

all:

$(DEFFILE): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile $(CONFIGFILE)
	$(Q)$(DLLTOOL) --export-all-symbols --kill-at --output-def $O/all.def $(OBJS) $(EXTRA_OBJS)
	$(Q)grep -E '( *_ZTI)|( *_ZThn)|( *_ZTv0)|EXPORTS' $O/all.def | sed 's/ @.*//' >$(DEFFILE)

$O/$(TARGET): $(DEFFILE)

  endif
endif

PLEXE_NEED_MSG4 := $(shell echo ${OMNETPP_VERSION} | grep "^5" >/dev/null 2>&1; echo $$?)
ifneq ($(PLEXE_NEED_MSG4),0)
  MSGCOPTS += --msg4
endif

ifeq ($(WITH_OSG), yes)
  OMNETPP_LIBS += $(OSG_LIBS)
endif

# <<<
#------------------------------------------------------------------------------

# Main target
all: $(TARGET_DIR)/$(TARGET)

$(TARGET_DIR)/% :: $O/%
	@mkdir -p $(TARGET_DIR)
	$(Q)$(LN) $< $@
ifeq ($(TOOLCHAIN_NAME),clangc2)
	$(Q)-$(LN) $(<:%.dll=%.lib) $(@:%.dll=%.lib)
endif

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile $(CONFIGFILE)
	@$(MKPATH) $O
	@echo Creating shared library: $@
	$(Q)$(SHLIB_LD) -o $O/$(TARGET) $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS) $(LDFLAGS)
	$(Q)$(SHLIB_POSTPROCESS) $O/$(TARGET)

.PHONY: all clean cleanall depend msgheaders smheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE) | msgheaders smheaders
	@$(MKPATH) $(dir $@)
	$(qecho) "$<"
	$(Q)$(CXX) -c $(CXXFLAGS) $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(qecho) MSGC: $<
	$(Q)$(MSGC) -s _m.cc -MD -MP -MF $O/$(basename $<)_m.h.d $(MSGCOPTS) $?

%_sm.cc %_sm.h: %.sm
	$(qecho) SMC: $<
	$(Q)$(SMC) -c++ -suffix cc $(SMCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

smheaders: $(SMFILES:.sm=_sm.h)

clean:
	$(qecho) Cleaning $(TARGET)
	$(Q)-rm -rf $O
	$(Q)-rm -f $(TARGET_DIR)/$(TARGET)
	$(Q)-rm -f $(TARGET_DIR)/$(TARGET:%.dll=%.lib)
	$(Q)-rm -f $(call opp_rwildcard, . , *_m.cc *_m.h *_sm.cc *_sm.h)

cleanall:
	$(Q)$(MAKE) -s clean MODE=release
	$(Q)$(MAKE) -s clean MODE=debug
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

# include all dependencies
-include $(OBJS:%=%.d) $(MSGFILES:%.msg=$O/%_m.h.d)
