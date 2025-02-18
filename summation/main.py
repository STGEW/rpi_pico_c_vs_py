import time
from machine import UART, Pin
import os

SUM_UNTIL = 1000000

uart0 = UART(
    0, baudrate=115200, tx=Pin(0), rx=Pin(1))
os.dupterm(uart0, 0)

start_time = time.ticks_us()
sum_result = sum(range(1, SUM_UNTIL + 1))
end_time = time.ticks_us()

print(f"Sum 1...{SUM_UNTIL}: {end_time - start_time} microseconds")

while True:
    print("I'm done!")
    time.sleep(1)
