#include <stdio.h>
#include "pico/stdlib.h"


#define FACTORIAL_VALUE 20


uint32_t factorial(uint32_t n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int main() {
    setup_default_uart();
    
    uint64_t start_time = time_us_64();
    volatile uint32_t fact = factorial(FACTORIAL_VALUE);
    uint64_t end_time = time_us_64();
    printf(
        "Factorial %d: %llu microseconds\n",
        FACTORIAL_VALUE,
        end_time - start_time);

    while (true) {
        printf("I'm done!\n");
        sleep_ms(1000);
    }

    return 0;
}

