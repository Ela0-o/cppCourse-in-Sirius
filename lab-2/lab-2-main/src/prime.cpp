#include <iostream>
#include "prime.h"
#include <vector>

int num_less(int n){
    int k = 0;
    std::vector<bool> primes (n + 1, true);
    primes[0] = primes[1] = false;
    for (int i = 2; i * i <= n; ++i)
        if (primes[i])
            for (int j = i * i; j <= n; j += i)
                primes[j] = false;
    for (int i = 0; i <= n; i++)
        if (primes[i])
            k++;
    return k;
}