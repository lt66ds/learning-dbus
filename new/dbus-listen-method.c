#include <stdio.h>
#include <unistd.h>
#include <dbus/dbus.h>

int main()
{
	DBusError error;
	DBusConnection *connection;
	int ret;
	dbus_bool_t flag;
	dbus_error_init(&error);
	connection=dbus_bus_get(DBUS_BUS_SESSION,&error);
	if (dbus_error_is_set(&error))
	{
		printf("error\n");
		exit(1);
	}
	flag=dbus_bus_register(connection,&error);
	ret=dbus_bus_request_name(connection,"org.jinhui.dbus",DBUS_NAME_FLAG_ALLOW_REPLACEMENT,&error);
	printf("request name successfully\n");
	if (dbus_error_is_set(&error))
	{
		printf("error\n");
		exit(1);
	}
	dbus_bus_add_match(connection, "type='signal',interface='test.signal.Type'",&error);
	dbus_connection_flush(connection);
	DBusMessage *msg;
	while ( 1 )
	{
		flag=dbus_connection_read_write(connection,-1);
		msg=dbus_connection_pop_message(connection);
		printf("received message\n");
		if (flag)
		{
			printf("Flag is true\n");
		}
	}
	
	dbus_connection_unref(connection);
}
