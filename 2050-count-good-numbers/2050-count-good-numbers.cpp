#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

// Function for modular exponentiation: (base^exp) % MOD
long long powerMod(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)  // If exponent is odd, multiply base
            result = (result * base) % mod;
        base = (base * base) % mod;  // Square the base
        exp /= 2;  // Reduce exponent by half
    }
    return result;
}

class Solution {
public:
    int countGoodNumbers(long long n) {
        long long even_count = (n + 1) / 2;  // Count of even-indexed positions
        long long odd_count = n / 2;         // Count of odd-indexed positions

        long long even_part = powerMod(5, even_count, MOD);  // Compute 5^(even_count) % MOD
        long long odd_part = powerMod(4, odd_count, MOD);    // Compute 4^(odd_count) % MOD

        return (even_part * odd_part) % MOD;  // Final result under modulo
    }
};

