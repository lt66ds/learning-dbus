#include <dbus/dbus.h>
#include <stdio.h>
#include <stdlib.h>
 
static void check_and_abort(DBusError *error);
 
int main() {
    DBusConnection *connection = NULL;
    DBusError error;
    DBusMessage *msgQuery = NULL;
    DBusMessage *msgReply = NULL;
    DBusMessageIter arg;
    const char *busName = "org.jinhui.dbus";
 
    dbus_error_init(&error);
    connection = dbus_bus_get(DBUS_BUS_SESSION, &error);
    check_and_abort(&error);
 
 
    msgQuery = dbus_message_new_method_call(
        busName,
        "/",
        "org.jinhui.iface",
        "hello");

    char *buffer="hello dbus service";

    dbus_message_iter_init_append (msgQuery,&arg);
    if(!dbus_message_iter_append_basic (&arg,DBUS_TYPE_STRING,&buffer)){
        fprintf(stderr,"Out Of Memory!/n");
        return -1;
    }
 
    msgReply = dbus_connection_send_with_reply_and_block(connection, msgQuery, 1000, &error);
    check_and_abort(&error);
    dbus_message_unref(msgQuery);
    
    char *res;
    dbus_message_get_args(msgReply, &error, DBUS_TYPE_STRING, &res);
	printf("Received :  %s\n", res);
     
    dbus_message_unref(msgReply);
     
    return 0;
}
 
static void check_and_abort(DBusError *error) {
    if (!dbus_error_is_set(error)) return;
    puts(error->message);
    abort();
}
