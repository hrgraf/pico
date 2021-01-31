import machine
import time
import ustruct

pin = machine.Pin(25, machine.Pin.OUT)
uart = machine.UART(1,31250)

notes = [60,61,62,63,64,63,62,61]

while True:
  for x in notes:
    pin.value(1)
    uart.write(ustruct.pack("bbb",0x90,x,0x40))
    time.sleep(0.5)
    pin.value(0)
    time.sleep(0.5)
    uart.write(ustruct.pack("bbb",0x90,x,0x00))
    