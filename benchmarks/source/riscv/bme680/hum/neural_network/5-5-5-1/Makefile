TREEROOT	= ../../../../../../..
include $(TREEROOT)/conf/setup.conf

TARGET		= riscv
TARGET-ARCH	= riscv32-elf

PROGRAM		= neural_network

PORT		= ../port
LIBOS		= mOS
TOOLSLIB	= $(TREEROOT)/tools/tools-lib
INCLUDES	= -I$(PREFIX)/include -I../port/  -I$(TREEROOT)/sys/include -I$(TREEROOT)/sys/kern/superH -I$(TREEROOT)/benchmarks/include -I$(TREEROOT)/sys/libOS/port
OPTFLAGS	= -O0
CFLAGS		= $(TARGET-ARCH-FLAGS) -march=rv32imfd -mabi=ilp32d -Wall
ASFLAGS		= --march=rv32imfd --mabi=ilp32d
LDFLAGS		= -Ttext $(LOADADDR) -L$(TOOLSLIB)/$(TARGET) -L$(TREEROOT)/sys/libOS/$(LIBOS) -Map $(PROGRAM).map
LOADADDR	= 0x08004000


OBJS	=\
	init-$(TARGET).o\
	$(PROGRAM).o\


all:	$(PROGRAM) $(PROGRAM).sr

$(PROGRAM): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $@ -lprintf -lc -lgcc -lgloss -lm

$(PROGRAM).sr:$(PROGRAM)
	$(OBJCOPY) -O srec $(PROGRAM) $@

$(PROGRAM).o: $(PROGRAM).c Makefile
	$(CC) $(CFLAGS) $(OPTFLAGS) $(INCLUDES) -c $(PROGRAM).c

init-$(TARGET).o: init-$(TARGET).S
	$(CPP) init-$(TARGET).S > init-$(TARGET).i; $(AS) $(ASFLAGS) init-$(TARGET).i -o $@

clean:
	$(RM) init-$(TARGET).i *.o $(PROGRAM) $(PROGRAM).sr $(PROGRAM).map

install: all
	cp $(PROGRAM).sr ../../../
