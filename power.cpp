int Solution::pow(int x, int n, int d) {
    long long ans = 1;
    long long base = (long long) x;
    if (base < 0) {
        base = (base+d) % d;
    }
    base %= d;
    while (n) {
        if (n & 1) {
            ans = (ans*base) % d;
        }
        base = (base*base) % d;
        n /= 2;
    }
    
    return ans%d;
}

