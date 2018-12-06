MATLAB_ROOT = /Applications/MATLAB_R2018b.app
MAKEFILE = run_usrp_tx_mex.mk

include run_usrp_tx_mex.mki


SRC_FILES =  \
	run_usrp_tx_mexutil.c \
	run_usrp_tx_data.c \
	run_usrp_tx_initialize.c \
	run_usrp_tx_terminate.c \
	run_usrp_tx.c \
	SDRuTransmitter.c \
	SDRuBase.c \
	SystemProp.c \
	SystemCore.c \
	error.c \
	checkIPAddressFormat.c \
	deleteDriver.c \
	mapiPrivate.c \
	reportDrivers.c \
	warning.c \
	checkBundledIP.c \
	getSDRuList.c \
	strcmp.c \
	_coder_run_usrp_tx_info.c \
	_coder_run_usrp_tx_api.c \
	_coder_run_usrp_tx_mex.c \
	c_mexapi_version.c

MEX_FILE_NAME_WO_EXT = run_usrp_tx_mex
MEX_FILE_NAME = $(MEX_FILE_NAME_WO_EXT).mexmaci64
TARGET = $(MEX_FILE_NAME)

BlockModules_LIBS = "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/bin/maci64/libmwusrp_uhd_capi.dylib" 
SYS_LIBS = $(BlockModules_LIBS) 


#
#====================================================================
# gmake makefile fragment for building MEX functions using Unix
# Copyright 2007-2016 The MathWorks, Inc.
#====================================================================
#

OBJEXT = o
.SUFFIXES: .$(OBJEXT)

OBJLISTC = $(SRC_FILES:.c=.$(OBJEXT))
OBJLISTCPP  = $(OBJLISTC:.cpp=.$(OBJEXT))
OBJLIST  = $(OBJLISTCPP:.cu=.$(OBJEXT))

target: $(TARGET)

ML_INCLUDES = -I "$(MATLAB_ROOT)/simulink/include"
ML_INCLUDES+= -I "$(MATLAB_ROOT)/toolbox/shared/simtargets"
SYS_INCLUDE = $(ML_INCLUDES)

# Additional includes

SYS_INCLUDE += -I "/Users/kj23458/Dropbox/UT\ Austin/EE\ 381K/ee381k17project/project/codegen/mex/run_usrp_tx"
SYS_INCLUDE += -I "/Users/kj23458/Dropbox/UT\ Austin/EE\ 381K/ee381k17project/project"
SYS_INCLUDE += -I "./interface"
SYS_INCLUDE += -I "$(MATLAB_ROOT)/extern/include"
SYS_INCLUDE += -I "/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/include"
SYS_INCLUDE += -I "."

EML_LIBS = -lemlrt -lcovrt -lut -lmwmathutil 
SYS_LIBS += $(CLIBS) $(EML_LIBS)


EXPORTFILE = $(MEX_FILE_NAME_WO_EXT)_mex.map
ifeq ($(Arch),maci)
  EXPORTOPT = -Wl,-exported_symbols_list,$(EXPORTFILE)
  COMP_FLAGS = -c $(CFLAGS)
  CXX_FLAGS = -c $(CXXFLAGS)
  LINK_FLAGS = $(filter-out %mexFunction.map, $(LDFLAGS))
else ifeq ($(Arch),maci64)
  EXPORTOPT = -Wl,-exported_symbols_list,$(EXPORTFILE)
  COMP_FLAGS = -c $(CFLAGS)
  CXX_FLAGS = -c $(CXXFLAGS)
  LINK_FLAGS = $(filter-out %mexFunction.map, $(LDFLAGS)) -Wl,-rpath,@loader_path
else
  EXPORTOPT = -Wl,--version-script,$(EXPORTFILE)
  COMP_FLAGS = -c $(CFLAGS) $(OMPFLAGS)
  CXX_FLAGS = -c $(CXXFLAGS) $(OMPFLAGS)
  LINK_FLAGS = $(filter-out %mexFunction.map, $(LDFLAGS)) 
endif
LINK_FLAGS += $(OMPLINKFLAGS)
ifeq ($(Arch),maci)
  LINK_FLAGS += -L$(MATLAB_ROOT)/sys/os/maci
endif
ifeq ($(EMC_CONFIG),optim)
  ifeq ($(Arch),mac)
    COMP_FLAGS += $(CDEBUGFLAGS)
    CXX_FLAGS += $(CXXDEBUGFLAGS)
  else
    COMP_FLAGS += $(COPTIMFLAGS)
    CXX_FLAGS += $(CXXOPTIMFLAGS)
  endif
  LINK_FLAGS += $(LDOPTIMFLAGS)
else
  COMP_FLAGS += $(CDEBUGFLAGS)
  CXX_FLAGS += $(CXXDEBUGFLAGS)
  LINK_FLAGS += $(LDDEBUGFLAGS)
endif
LINK_FLAGS += -o $(TARGET)
LINK_FLAGS +=  -L/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/bin/maci64 -Wl,-rpath,/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/bin/maci64 -L/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/bin/maci64 -Wl,-rpath,/Users/kj23458/Documents/MATLAB/SupportPackages/R2018b/toolbox/shared/sdr/sdru/bin/maci64

CCFLAGS = $(COMP_FLAGS) -std=c99   $(USER_INCLUDE) $(SYS_INCLUDE)
CPPFLAGS = $(CXX_FLAGS) -std=c++11   $(USER_INCLUDE) $(SYS_INCLUDE)

%.$(OBJEXT) : %.c
	$(CC) $(CCFLAGS) "$<"

%.$(OBJEXT) : %.cpp
	$(CXX) $(CPPFLAGS) "$<"

# Additional sources

%.$(OBJEXT) : /Users/kj23458/Dropbox/UT\ Austin/EE\ 381K/ee381k17project/project/%.c
	$(CC) $(CCFLAGS) "$<"

%.$(OBJEXT) : /Users/kj23458/Dropbox/UT\ Austin/EE\ 381K/ee381k17project/project/codegen/mex/run_usrp_tx/%.c
	$(CC) $(CCFLAGS) "$<"

%.$(OBJEXT) : interface/%.c
	$(CC) $(CCFLAGS) "$<"



%.$(OBJEXT) : /Users/kj23458/Dropbox/UT\ Austin/EE\ 381K/ee381k17project/project/%.cpp
	$(CXX) $(CPPFLAGS) "$<"

%.$(OBJEXT) : /Users/kj23458/Dropbox/UT\ Austin/EE\ 381K/ee381k17project/project/codegen/mex/run_usrp_tx/%.cpp
	$(CXX) $(CPPFLAGS) "$<"

%.$(OBJEXT) : interface/%.cpp
	$(CXX) $(CPPFLAGS) "$<"



%.$(OBJEXT) : /Users/kj23458/Dropbox/UT\ Austin/EE\ 381K/ee381k17project/project/%.cu
	$(CC) $(CCFLAGS) "$<"

%.$(OBJEXT) : /Users/kj23458/Dropbox/UT\ Austin/EE\ 381K/ee381k17project/project/codegen/mex/run_usrp_tx/%.cu
	$(CC) $(CCFLAGS) "$<"

%.$(OBJEXT) : interface/%.cu
	$(CC) $(CCFLAGS) "$<"




$(TARGET): $(OBJLIST) $(MAKEFILE)
	$(LD) $(EXPORTOPT) $(OBJLIST) $(LINK_FLAGS) $(SYS_LIBS)

#====================================================================

