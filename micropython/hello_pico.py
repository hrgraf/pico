print("Blink the LED and measure the temperature")
print("(press Ctrl-C to stop)")

import machine
import time

led = machine.Pin(25, machine.Pin.OUT)

temp = machine.ADC(4)
f = 3.3 / 65535

while True:
    led.value(1)
    time.sleep(0.2)
    
    v = temp.read_u16() * f
    deg = 27 - (v - 0.706)/0.001721
    print("%1.3fV => %2.2f°C" % (v, deg))
    
    led.value(0)
    time.sleep(0.8)
