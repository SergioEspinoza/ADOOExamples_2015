
INCLUDE+=./
INCLUDE+=../FCW1

CC=gcc
CXX=g++

OUTPUT_DIR=./obj

LIB_DIRS=./

INC_DIRS+=-I../FwProfile
INC_DIRS+=-I../


CFLAGS=$(INC_DIRS) -Wall -fpic -L$(LIB_DIRS)


FC1_DIR=../FwProfile
ADOOFSM_DIR=./

FC1LIB_OBJS+=FwPrConfig.o
FC1LIB_OBJS+=FwPrCore.o
FC1LIB_OBJS+=FwPrDCreate.o
FC1LIB_OBJS+=FwPrSCreate.o
FC1LIB_OBJS+=FwRtConfig.o
FC1LIB_OBJS+=FwRtCore.o
FC1LIB_OBJS+=FwSmAux.o
FC1LIB_OBJS+=FwSmConfig.o
FC1LIB_OBJS+=FwSmCore.o
FC1LIB_OBJS+=FwSmDCreate.o
FC1LIB_OBJS+=FwSmSCreate.o


ADOO_FSM_OBJS+=TCPFSM.o
ADOO_FSM_OBJS+=TCPFSMMain.o


FC1LIB_OBJS_OUT=$(patsubst %,$(OUTPUT_DIR)/%,$(FC1LIB_OBJS))
ADOO_FSM_OBJS_OUT=$(patsubst %,$(OUTPUT_DIR)/%,$(ADOO_FSM_OBJS))

TARGETS+=fc1lib.so
TARGETS+=adoo_fsm

all: dirs $(TARGETS)

fc1lib.so: $(FC1LIB_OBJS_OUT)
	$(CC) $(CFLAGS) --shared -o $@ $^ 

adoo_fsm: $(ADOO_FSM_OBJS_OUT)
	$(CC) $(CFLAGS) -lpthread fc1lib.so -o $@ $^ 

dirs:
	mkdir -p obj


.PHONY: clean
clean:
	rm -f $(FC1LIB_OBJS_OUT) $(ADOO_FSM_OBJS) $(TARGETS)


# 
# FC1 Lib C file rule
$(OUTPUT_DIR)/%.o: $(FC1_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $< 

# 
#  ADOO FSM C file rule
$(OUTPUT_DIR)/%.o: $(ADOOFSM_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $< 


#
# C++ file generic rule
$(OUTPUT_DIR)/%.o: %.cpp
	$(CXX) $(CFLAGS) -c -o $@ $< 

