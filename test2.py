from dbus.mainloop.glib import DBusGMainLoop
import gobject
import dbus
DBusGMainLoop(set_as_default=True)
loop=DBusGMainLoop()
res=dbus.SessionBus(mainloop=loop)
print res


