
#include <stdio.h>
#include <math.h>
#include <assert.h>

// A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers 
// is 9009 = 91 * 99. Find the largest palindrome made from the product of two 3-digit numbers.

int is_palindrome(int x) {
    int reverse = 0;
    int original = x;
    int exp = 0;
    while (x > 0) {
        reverse = reverse * 10 + ((x%10) * pow(10, exp));
        x = x/10;
    }
    return reverse == original;
}

void largest_palindrome(int * result) {
    int last_palindrome = 0;

    for (int i = 999; i > 99; i--) {
        for (int j = i; j > 99; j--) {
            if (is_palindrome(i * j) && (i*j) > last_palindrome) {
                result[0] = i;
                result[1] = j;
                last_palindrome = i * j;
            }
        }
    }
}



int main() {
    assert(is_palindrome(101) == 1);
    int arr[2];
    largest_palindrome(arr);
    printf("\nThe largest three digit palindrome is formed by %d and %d: %d\n\n", arr[0], arr[1], arr[0] * arr[1]);

}