import dbus
bus = dbus.SessionBus()
obj = bus.get_object('org.jinhui.dbus','/')
print 'connected'
res = obj.hello('hello from python',dbus_interface='org.jinhui.iface')
print res
