#include <bits/stdc++.h>

// Sieve of Eratosthenes 
class EratoSieve {
public:
    EratoSieve(int64_t n) {
        this->isPrimeFlag.resize(n + 1);
        for (int64_t i = 0; i <= n; ++i) {
            this->isPrimeFlag[i] = true;
        }

        this->isPrimeFlag[0] = this->isPrimeFlag[1] = false;
        for (int64_t i = 2; i <= n; ++i) {
            if (this->isPrimeFlag[i]) {
                for (int64_t j = 2 * i; j <= n; j += i) {
                    this->isPrimeFlag[j] = false;
                }
            }
        }
    }

    ~EratoSieve() = default;

    // return true if n is a prime number
    bool isPrime(int64_t n) const noexcept {
        return this->isPrimeFlag[n];
    }

    // return the number of prime numbers which is "<= n"
    int64_t nums(int n) const noexcept {
        int64_t cnt = 0;
        for (int64_t i = 2; i <= n; ++i) {
            if (this->isPrimeFlag[i]) {
                ++cnt;
            }
        }

        return cnt;
    }

    // return vector of primes which are "<= n"
    std::vector<int64_t> primes(int n) const noexcept {
        std::vector<int64_t> ret;
        for (int64_t i = 2; i <= n; ++i) {
            if (this->isPrimeFlag[i]) {
                ret.push_back(i);
            }
        }

        return ret;
    }

private:
    std::vector<bool> isPrimeFlag; // if isPrimeFlag[i] is true, i is prime number.
};
