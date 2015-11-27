#include <stdio.h>
#include <unistd.h>
#include <dbus/dbus.h>

int main()
{
	DBusError *error;
	DBusConnection *connection;
	int ret;
	dbus_error_init(error);
	connection=dbus_bus_get(DBUS_BUS_SESSION,error);
	if (dbus_error_is_set(error))
	{
		printf("error\n");
		exit(1);
	}
	ret=dbus_bus_request_name(connection,"org.jinhui.dbus",DBUS_NAME_FLAG_ALLOW_REPLACEMENT,error);
	if (dbus_error_is_set(error))
	{
		printf("error\n");
		exit(1);
	}
	while (1)
	{
		printf("org.jinhui.dbus running\n");
	}
	
	dbus_connection_unref(connection);
}
