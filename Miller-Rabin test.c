#include <stdbool.h>
#include <stdio.h>
int mod(int a, int b, int m) {
    int r = 0;
    a = a % m;
    while (b > 0)
    {
        if (b & 1) {
            r = (r + a) % m;
        }
        b = (b >> 1);
        a = (a + a) % m;
    }
    return r;
}

int power(int a, int d, int n)
{
    int r = 1;
    a = a % n;

    while (d > 0)
    {
        if (d & 1)
            r = mod(r, a, n);

        d = (d >> 1);

        a = mod(a, a, n);
    }

    return r;
}

bool check(int a, int d, int n)
{
    int x = power(a, d, n);

    if (x == 1 || x == n - 1)
        return true;

    while (d != n - 1)
    {
        x = mod(x, x, n);
        d = (d << 1);

        if (x == 1)
            return false;

        if (x == n - 1)
            return true;
    }

    return false;
}


//valid for primes between 100 and 9,000,000
bool miller_rabin(int n)
{
    int d = n - 1;
    while (d % 2 == 0) {
        d >>= 1;
    }
    if (!check(31, d, n)) {
        return false;
    }
    if (!check(73, d, n)) {
        return false;
    }
    return true;
}

//driver code
int main(void) {
    int number_of_primes = 0;
    for (int i = 100; i < 1000000; ++i) {
        if (miller_rabin(i)) {
            ++number_of_primes;
        }
    }
    printf("there are %d, primes between 100 and 1000000", number_of_primes);
    
}