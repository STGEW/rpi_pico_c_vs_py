#include <stdio.h>
#include "pico/stdlib.h"


#define SUM_UNTIL 1000000


int main() {
    stdio_init_all();
    
    uint64_t start_time = time_us_64();
    volatile uint64_t sum = 0;
    for (uint32_t i = 1; i <= SUM_UNTIL; i++) {
        sum += i;
    }
    uint64_t end_time = time_us_64();
    printf("Summ 1...%d: %llu microseconds \n", SUM_UNTIL, end_time - start_time);

    while (true) {
        printf("I'm done!\n");
        sleep_ms(1000);
    }

    return 0;
}

