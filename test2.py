from dbus.mainloop.glib import DBusGMainLoop
import gobject
DBusGMainLoop(set_as_default=True)
loop=gobject.MainLoop()
loop.run()

