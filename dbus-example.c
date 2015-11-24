#define DBUS_API_SUBJECT_TO_CHANGE
#include <dbus/dbus.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main (int argc, char **argv)
{
  DBusConnection *connection;
  DBusError error;
  DBusMessage *message;
  DBusMessage *reply;
  int reply_timeout;
  char **service_list;
  int service_list_len;
  int i;
  
  dbus_error_init (&error);

  connection = dbus_bus_get (DBUS_BUS_SYSTEM,
                               &error);
  if (connection == NULL)
    {
      fprintf(stderr, "Failed to open connection to bus: %s\n",
                  error.message);
      dbus_error_free (&error);
      exit (1);
    }

  /* Construct the message */
  message = dbus_message_new_method_call ("org.freedesktop.DBus",       /*service*/
                                                                            "/org/freedesktop/DBus",     /*path*/
                                                                            "org.freedesktop.DBus",      /*interface*/
                                                                            "ListNames"); 

  /* Call ListServices method */
  reply_timeout = -1;   /*don't timeout*/
  reply = dbus_connection_send_with_reply_and_block (connection,
                                                                                           message, reply_timeout, 
                                                                                           &error);

  if (dbus_error_is_set (&error))
    {
      fprintf (stderr, "Error: %s\n",
                   error.message);
       exit (1);
    }

/* Extract the data from the reply */
 if (!dbus_message_get_args (reply, &error, 
                               DBUS_TYPE_ARRAY_AS_STRING, &service_list))
   { 
      fprintf (stderr, "Failed to complete ListServices call: %s\n",
                  error.message);
      exit (1);
    }
  dbus_message_unref (reply);
  dbus_message_unref (message);

  /* Print the results */
 
  printf ("Services on the message bus:\n");
  i = 0;
  while (i < service_list_len)
    {
      //assert (service_list[i] != NULL);
      printf ("  %s\n", service_list[i]);
      ++i;
    }
  //assert (service_list[i] == NULL);

  for (i = 0; i < service_list_len; i++)
    free (service_list[i]);
  free (service_list);

  return 0;
}
