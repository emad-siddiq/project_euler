#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <math.h>

// The prime factors of 13195 are 5, 7, 13 & 29
// What is the largest prime factor of the number 600851475143?


// Miller-Rabin primality test
int is_probably_prime(long long N) {
    if (N <= 1) return 0;
    int a[] = {2, 3, 5, 7, 11};

    for (int i = 0; i < 5; i++) {
        long long base = a[i];
        long long res = 1, exp = N-1;

        while (exp > 0) {
            if (exp & 1) 
                res = (res * base) % N;
            base = (base * base) % N;
            exp >>= 1;
        }

        if (res != 1) return 0;
    }
    return 1;
}


long long largest_prime_factor(long long n) {
    long long largest = -1;
    
    // Remove even factors
    while (n % 2 == 0) {
        largest = 2;
        n /= 2;
    }
    
    // Check odd factors up to sqrt(n)
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            if (is_probably_prime(i))
                largest = i;
            n /= i;
        }
    }
    
    // If remaining n is prime and larger
    if (n > 2 && is_probably_prime(n))
        largest = n;
    
    return largest;
}

int main() {
    assert(is_probably_prime(997) == 1);
    assert(is_probably_prime(999983) == 1);
    assert(is_probably_prime(999960) == 0);
    assert(largest_prime_factor(13195) == 29);
    long long x = largest_prime_factor(600851475143);
    printf("The largest prime factor of 600851475143 is: %lld\n", x);

}