#include <bits/stdc++.h>

class ModInt {
public:
    ModInt(int64_t v, int64_t m) 
      : val(v % m), mod(m)
    {
    }

    inline int64_t getVal() const noexcept {
        return this->val;
    }

    inline int64_t getMod() const noexcept {
        return this->mod;
    }

    inline ModInt operator - () const noexcept {
        return this->val ? ModInt(this->mod - this->val, this->mod) : ModInt(0, this->mod);
    }

    inline ModInt operator + (const ModInt& r) const noexcept {
        return ModInt(*this) += r;
    }

    inline ModInt operator - (const ModInt& r) const noexcept {
        return ModInt(*this) -= r;
    }

    inline ModInt operator * (const ModInt& r) const noexcept {
        return ModInt(*this) *= r;
    }

    inline ModInt operator / (const ModInt& r) const noexcept {
        return ModInt(*this) /= r;
    }

    inline ModInt& operator += (const ModInt& r) noexcept {
        this->val += r.val;
        this->val %= this->mod;
        return *this;
    }

    inline ModInt& operator -= (const ModInt& r) noexcept {
        this->val -= r.val;
        if (this->val < 0) {
            this->val += this->mod;
        }
        return *this;
    }

    inline ModInt& operator *= (const ModInt& r) noexcept {
        this->val = this->val * r.val % this->mod;
        return *this;
    }

    inline ModInt& operator /= (const ModInt& r) noexcept {
        int64_t a = r.val, b = this->mod, u = 1, v = 0;
        while (b) {
            int64_t t = a / b;
            a -= t * b; std::swap(a, b);
            u -= t * v; std::swap(u, v);
        }
        this->val = this->val * u % this->mod;
        if (val < 0) {
            val += this->mod;
        }

        return *this;
    }

    inline bool operator == (const ModInt& r) const noexcept {
        return this->val == r.val;
    }

    inline bool operator != (const ModInt& r) const noexcept {
        return this->val != r.val;
    }

    friend std::ostream& operator << (std::ostream& os, const ModInt& x) noexcept {
        return os << x.val;
    }

private:
    int64_t val;
    int64_t mod;
};

ModInt modpow(int64_t a, int64_t n, int64_t mod) {
    ModInt ret(1, mod);
    ModInt ma(a, mod);
    while (n > 0) {
        if (n & 1) {
            ret *= ma;
        }
        ma *= ma;
        n >>= 1;
    }

    return ret;
}

ModInt modconb(int64_t n, int64_t k, int64_t mod) {
    ModInt nu(1, mod);
    ModInt de(1, mod);

    for (int64_t i = 0; i < k; ++i) {
        nu *= ModInt(n-i, mod);
        de *= ModInt(i+1, mod);
    }

    return nu / de;
}

