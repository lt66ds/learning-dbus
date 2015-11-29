CC=gcc
LIBS=`pkg-config --cflags --libs dbus-1`
RM=rm

all:send.bin listen.bin

send.bin:send.c
	${CC} -o $@ $< ${LIBS}

listen.bin: listen.c
	${CC} -o $@ $< ${LIBS}

.PHONY:clean
clean:
	rm *.bin *.o
