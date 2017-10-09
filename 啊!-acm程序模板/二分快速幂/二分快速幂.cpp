long long bigpow(int x, int y)
{
    long long ret = 1;
    long long tmp = x;
    while (y > 0) {
        if (y & 1) ret *= tmp;
        y >>= 1;
        tmp *= tmp;
    }
    return ret;
}
