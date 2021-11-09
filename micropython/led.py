import machine
import utime

led = machine.Pin(15, machine.Pin.OUT) # external
#led = machine.Pin(25, machine.Pin.OUT) # internal

while True:
    led.toggle()
    utime.sleep(1)
