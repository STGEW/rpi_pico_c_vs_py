import time
from machine import UART, Pin
import os


ITERATIONS = 100000


uart0 = UART(
    0, baudrate=115200, tx=Pin(0), rx=Pin(1))
os.dupterm(uart0, 0)

def multiply_matrices(A, B):
    C = [[0, 0, 0] for _ in range(3)]
    for i in range(3):
        for j in range(3):
            for k in range(3):
                C[i][j] += A[i][k] * B[k][j]
    return C

A = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

B = [
    [9, 8, 7],
    [6, 5, 4],
    [3, 2, 1]
]

start_time = time.ticks_us()

for _ in range(ITERATIONS):
    C = multiply_matrices(A, B)

end_time = time.ticks_us()

print(f"Matrix multiplication ({ITERATIONS} times): {end_time - start_time} microseconds")

print("Resulting matrix:")
for row in C:
    print(" ".join(map(str, row)))

while True:
    print("I'm done!")
    time.sleep(1)
