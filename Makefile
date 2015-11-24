APPNAME=DBUS_DEMO
CC=gcc
LIBS=`pkg-config --cflags --libs dbus-1`

${APPNAME}:dbus-example.c
	${CC} $< -o $@ $(LIBS)

.PHONY:clean
clean:
	${RM} *.o ${APPNAME}
