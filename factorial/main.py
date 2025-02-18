import time
from machine import UART, Pin
import os


FACTORIAL_VALUE = 20

def factorial(n):
    if n == 0:
        return 1
    return n * factorial(n - 1)

uart0 = UART(
    0, baudrate=115200, tx=Pin(0), rx=Pin(1))
os.dupterm(uart0, 0)

start_time = time.ticks_us()
fact = factorial(FACTORIAL_VALUE)
end_time = time.ticks_us()

print(f"Factorial {FACTORIAL_VALUE}: {end_time - start_time} microseconds")

while True:
    print("I'm done!")
    time.sleep(1)
