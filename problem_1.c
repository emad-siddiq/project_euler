#include <stdio.h>
#include <assert.h>

// Problem 1
// If we list all the natural numbers below 10
// that are multiples of 3 or 5, we get 3, 5, 6, 9.
// The sum of these multiples is 23.
// Find the sum of all multiples of 3 or 5, below 1000.

int sum_multiples_below_3_or_5(int n) {
    int total = 0;
    for (int i = 1; 3 * i < n; i++){
        total += 3 * i;
    };

    for (int i = 1; 5 * i < n; i++){
        if (5*i % 3 != 0){
            total += 5 * i;
        }
    };
    return total;
}

int main()
{
    int x = sum_multiples_below_3_or_5(10);
    assert(x == 23);

    int y = sum_multiples_below_3_or_5(1000);
    assert(y == 233168);

    printf("Sum of multiples of 3 or 5 below 1000 is: %d\n", y);
}
