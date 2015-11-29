CC=gcc
LIBS=`pkg-config --cflags --libs dbus-1`
RM=rm

all: dbus-caller.bin  dbus-listen-method.bin


dbus-caller.bin: dbus-caller.c
	${CC} $< -o $@ ${LIBS}

dbus-listen-method.bin:dbus-listen-method.c
	${CC} $< -o $@ ${LIBS}




.PHONY:clean
clean:
	rm *.bin *.o
