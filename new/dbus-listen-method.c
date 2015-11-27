#include <stdio.h>
#include <unistd.h>
#include <dbus/dbus.h>

int reply_to_hello_method(DBusConnection *connection,DBusMessage *msg)
{
	DBusMessageIter iter;
	DBusMessageIter reIter;
	DBusMessage *reMsg;
	dbus_bool_t flag=dbus_message_iter_init(msg,&iter);
	int current_type;
	char *buffer;
	reMsg=dbus_message_new_method_return(msg);
	
	current_type=dbus_message_iter_get_arg_type(&iter);
	if (current_type==DBUS_TYPE_STRING)
		{
			dbus_message_iter_get_basic(&iter,&buffer);
			if (buffer!=NULL)
				printf("received Msg: %s\n",buffer);
		}
		dbus_message_iter_init_append(reMsg,&reIter);
		printf("ready to send message: %s\n",buffer);
		buffer[0]='r';
		buffer[1]='e';
		buffer[2]='p';
		buffer[3]='l';
		buffer[4]='y';
		dbus_message_iter_append_basic(&reIter,DBUS_TYPE_STRING,&buffer);
		dbus_connection_send(connection,reMsg,0);	
		dbus_connection_flush(connection);
}



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
	dbus_bus_add_match(connection, "type='signal',interface='org.jinhui.iface'",&error);
	dbus_connection_flush(connection);
	DBusMessage *msg;
	while ( 1 )
	{
		flag=dbus_connection_read_write(connection,1);
		msg=dbus_connection_pop_message(connection);
		if (!flag)
		{
			printf("Invalid message\n");		
			continue;
		}
		//printf("Message received\n");
		if (msg!=NULL && dbus_message_is_method_call(msg,"org.jinhui.iface","hello"))
		{
			printf("send to hello method\n");
			reply_to_hello_method(connection,msg);
		}
			
	
	}
	
	dbus_connection_unref(connection);
}
