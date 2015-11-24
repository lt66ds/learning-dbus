import dbus
bus = dbus.SessionBus()
obj = bus.get_object('org.fcitx.Fcitx','/inputmethod')
print obj
props = obj.Configure(dbus_interface='org.fcitx.Fcitx.InputMethod')
print props
