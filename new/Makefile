CC=gcc
LIBS=`pkg-config --cflags --libs dbus-1`
RM=rm

all: dbus-critical.bin

dbus-critical.bin: dbus-critical.c
	${CC} $< -o $@ ${LIBS}
.PHONY:clean
clean:
	rm *.bin *.o
