#include <stdio.h>
#include <math.h>

// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10
// without any remainder. What is the smallest positive number that is evenly divisible by all
// of the numbers from 1 to 20?


int evenly_divisable() {
    int i = 1;

    while (1) {
        int x = 20 * i;
        if (x%20 == 0) {
            for (int j = 19; j > 0; j--) {
                if (j == 1) {
                    return x;
                } else {
                    if (x % j != 0) {
                        j = 0;
                    }
                }
            }
        }
        i++;
        printf("Searching...\n");
    }
    return -1;
}

int main() {
    printf("The number is: %d", evenly_divisable());
}