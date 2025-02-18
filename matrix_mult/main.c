#include <stdio.h>
#include "pico/stdlib.h"

#define ITERATIONS 100000


void multiply_matrices(const int A[3][3], const int B[3][3], volatile int C[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    stdio_init_all();

    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    volatile int C[3][3];

    uint64_t start_time = time_us_64();
    for (int i = 0; i < ITERATIONS; i++) {
        multiply_matrices(A, B, C);
    }
    uint64_t end_time = time_us_64();

    printf("Matrix multiplication (%d times): %llu microseconds\n", 
           ITERATIONS, end_time - start_time);

    printf("Resulting matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    while (true) {
        printf("I'm done!\n");
        sleep_ms(1000);
    }

    return 0;
}
