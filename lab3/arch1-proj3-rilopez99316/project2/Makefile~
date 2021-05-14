all: drawing.elf

CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/ 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as
AR              = msp430-elf-ar

drawing.elf: drawing.o lcdutils.o lcddraw.o
	$(CC) $(CFLAGS) ${LDFLAGS} -o $@ $^ -lLcd -lTimer 

lcdutils: lcdutils.o

lcddraw: lcddraw.o

clean:
	rm -f *.a *.o *.elf

load: drawing.elf
	msp430loader.sh $^

