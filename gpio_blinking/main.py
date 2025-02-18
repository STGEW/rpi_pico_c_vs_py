import time
from machine import UART, Pin
import os

LED_PIN = 25
BLINK_COUNT = 1000000

uart0 = UART(
    0, baudrate=115200, tx=Pin(0), rx=Pin(1))
os.dupterm(uart0, 0)

led = Pin(LED_PIN, Pin.OUT)
start_time = time.ticks_us()

for _ in range(BLINK_COUNT):
    led.value(1)
    led.value(0)

end_time = time.ticks_us()

print(f"Blinking {BLINK_COUNT} times takes: {end_time - start_time} microseconds")

while True:
    led.value(1)
    time.sleep_ms(500)
    led.value(0)
    time.sleep_ms(500)
    print("I'm done!")