from machine import ADC, Pin
import time

adc0 = ADC(Pin(26))
adc1 = ADC(Pin(27))

while True:
    val0 = adc0.read_u16()
    val1 = adc1.read_u16()
    print('adc', val0, val1)
    time.sleep(1)