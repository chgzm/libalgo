#include <bits/stdc++.h>

// return true if n is a prime number
bool isPrime(int64_t n) noexcept {
    if (n == 1) {
        return false;
    }

    for (int64_t i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

// return the divisor of n
std::vector<int64_t> divisor(int64_t n) noexcept {
    std::vector<int64_t> ret;
    for (int64_t i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i != n / i) {
                ret.push_back(n / i);
            }
        }
    }
    std::sort(ret.begin(), ret.end());

    return ret;
}

// return the prime factors of n
std::map<int64_t, int64_t> primeFactor(int64_t n) noexcept {
    std::map<int64_t, int64_t> ret;
    for (int64_t i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            ++ret[i];
            n /= i;
        }
    }

    if (n != 1) {
        ret[n] = 1;
    }

    return ret;
}

