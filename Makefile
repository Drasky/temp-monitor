CFLAGS = -O2 -Wall
CC = g++
INSTALL = install
TARGET = /usr/local/bin
LIBS = -lwiringPi -lwiringPiDev

PROG_OBJS=temp-monitor.o
PROG=temp-monitor

all: temp-monitor

.c.o:
	$(CC) -c $(CFLAGS) -o $@ $<

temp-monitor: $(PROG_OBJS)
	$(CC) $(CFLAGS) $(PROG_OBJS) -o $(PROG) ${LIBS}

install: $(PROG)
	$(INSTALL) $(PROG) $(TARGET)/$(PROG)

clean:
	rm -f $(PROG_OBJS) $(PROG)

