#include <dbus/dbus.h>
#include <stdio.h>
#include <stdlib.h>
 
static void check_and_abort(DBusError *error);
 
int main() {
    DBusConnection *connection = NULL;
    DBusError error;
    DBusMessage *msgQuery = NULL;
    DBusMessage *msgReply = NULL;
    const char *interfaceName = NULL;
    int res=0;
 
    dbus_error_init(&error);
    connection = dbus_bus_get(DBUS_BUS_SYSTEM, &error);
    check_and_abort(&error);
 
    interfaceName = "org.freedesktop.UPower";
 
    msgQuery = dbus_message_new_method_call(
        interfaceName,
        "/org/freedesktop/UPower",
        "org.freedesktop.UPower",
        "SuspendAllowed");
 
    msgReply = dbus_connection_send_with_reply_and_block(connection, msgQuery, 1000, &error);
    check_and_abort(&error);
    dbus_message_unref(msgQuery);
 
    dbus_message_get_args(msgReply, &error, DBUS_TYPE_BOOLEAN, &res);
	printf("The Suspend action is allowed?:  %d\n", res);
     
    dbus_message_unref(msgReply);
     
    return 0;
}
 
static void check_and_abort(DBusError *error) {
    if (!dbus_error_is_set(error)) return;
    puts(error->message);
    abort();
}
