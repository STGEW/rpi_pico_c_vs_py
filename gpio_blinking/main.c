#include <stdio.h>
#include "pico/stdlib.h"


#define LED_PIN 25
#define BLINK_COUNT 1000000


int main() {
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    uint64_t start_time = time_us_64();
    for (int i = 0; i < BLINK_COUNT; i++) {
        gpio_put(LED_PIN, 1);
        gpio_put(LED_PIN, 0);
    }
    uint64_t end_time = time_us_64();
    printf(
        "Blinking %d times takes: %llu microseconds\n",
        BLINK_COUNT,
        end_time - start_time);

    while (1) {
        gpio_put(LED_PIN, 1);
        sleep_ms(500);
        gpio_put(LED_PIN, 0);
        sleep_ms(500);
        printf("I'm done!\n");
    }

    return 0;
}

