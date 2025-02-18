# rpi_pico_c_vs_py
A repository contains a code on C and Micropython which does the same 4 operations:
1) factorial of 20
2) summation from 1 to 1_000_000
3) matrix (3*3) multiplication 100_000 times
4) GPIO blinking 1_000_000 times

# To compile C code (f.e. factorial)
cd ./factorial
mkdir ./build
cd ./build
cmake .. && make
The result is factorial.uf2 file

# To upload Micropython code
cd ./factorial
mpremote a1 cp main.py :

# Results
Tested on Raspberry pi pico with micropython RPI_PICO-20241129-v1.24.1.uf2
Factorial 20:
C: 4 microseconds
micropython: 673 - 688 microseconds (168 times C code execution)

Summation 1...1_000_000:
C: 72_004 microseconds
micropython: 11_976_638 - 11_976_945 microseconds (~ almost 12 seconds) (166 times C code execution)

matrix mult 100_000 times:
C: 125_621 microseconds
micropython: 102_414_598 - 102_414_992 microseconds (815 times C code execution)

GPIO blinking 1_000_000 times:
C: 48_003 microseconds
micropython: 21_400_393 - 21_400_428 microseconds (~ 21 seconds) (445 times C code execution)

