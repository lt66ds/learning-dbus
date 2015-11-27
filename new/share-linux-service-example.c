    #include <stdio.h>

    #include <dbus/dbus.h>
 #include <unistd.h>
    int main()

    {

    DBusConnection *connection;

    DBusError error;

     
    int ret;
    dbus_error_init(&error);

	connection = dbus_bus_get(DBUS_BUS_STARTER, &error); 
	ret=dbus_bus_request_name(connection,"org.share.linux",DBUS_NAME_FLAG_ALLOW_REPLACEMENT,&error);

	if (dbus_error_is_set(&error))
	{
		printf("request name Failed\n");
	}
	printf("request name successfully\n");




/* DBUS_BUS_STARTER is

    
    the bus that started us */

    /* Do something here to make sure that the application was successfully

    started by DBus

    * Example could be something like
    */
    while (1)
    {
    	FILE *tmp;

    	tmp = fopen("/tmp/share-linux-service.result", "w");

    	fprintf(tmp,"share-linux service was started successfully");

    	fclose(tmp);
     
    	printf("share-linux running\n");
    	usleep(10000);
    /* After that you have the service up, so you can do whetever you like */
	}
    dbus_connection_unref(connection);

     

    return 0;

    }
