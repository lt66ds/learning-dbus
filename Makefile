APPNAME=DBUS_DEMO
CC=gcc
LIBS=`pkg-config --cflags --libs dbus-1`


all:${APPNAME}.bin dbus.bin dbus-tu.bin

${APPNAME}.bin:dbus-example.c
	${CC} $< -o $@ $(LIBS)

dbus.bin:dbus.c
	${CC} $< -o $@ ${LIBS}

dbus-tu.bin:dbus-tu.c
	${CC} $< -o $@ ${LIBS}

.PHONY:clean
clean:
	${RM} *.o ${APPNAME} *.bin
