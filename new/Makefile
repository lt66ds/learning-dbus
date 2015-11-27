CC=gcc
LIBS=`pkg-config --cflags --libs dbus-1`
RM=rm

all: dbus-suspend.bin dbus-hibernate.bin start-service.bin share-linux-service-example.bin dbus-listen.bin dbus-listen-method.bin dbus-server-example.bin
dbus-suspend.bin: dbus-suspend.c
	${CC} $< -o $@ ${LIBS}

dbus-hibernate.bin: dbus-hibernate.c
	${CC} $< -o $@ ${LIBS}

start-service.bin: start-service.c
	${CC} $< -o $@ ${LIBS}

share-linux-service-example.bin: share-linux-service-example.c
	${CC} $< -o $@ ${LIBS}

dbus-listen.bin:dbus-listen.c
	${CC} $< -o $@ ${LIBS}

dbus-listen-method.bin:dbus-listen-method.c
	${CC} $< -o $@ ${LIBS}

dbus-server-example.bin:dbus-server-example.c
	${CC} $< -o $@ ${LIBS}

.PHONY:clean
clean:
	rm *.bin *.o
