#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ull unsigned ll
#define lowbit(x) (x & (-x))
template <typename T>
inline void read(T &x)
{
    x = 0;
    char s = (char)getchar();
    bool f = false;
    while (!(s >= '0' && s <= '9'))
    {
        if (s == '-')
            f = true;
        s = (char)getchar();
    }
    while (s >= '0' && s <= '9')
    {
        x = (x << 1) + (x << 3) + s - '0';
        s = (char)getchar();
    }
    if (f)
        x = (~x) + 1;
}
template <typename T, typename... T1>
inline void read(T &x, T1 &...x1)
{
    read(x);
    read(x1...);
}
template <typename T>
inline void ckmin(T &x, T y)
{
    if (x > y)
        x = y;
}
template <typename T>
inline void ckmax(T &x, T y)
{
    if (x < y)
        x = y;
}
using namespace std;
constexpr int N = 2e5 + 5;
constexpr int mod = 1e9 + 7;
inline ll quickpow(ll a, int b = mod - 2)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            (res *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return res;
}
int n, k;
ll fac[N], ifac[N];
signed main()
{
    read(n, k);
    fac[0] = 1;
    for (int i = 1; i <= k; ++i)
        fac[i] = fac[i - 1] * i % mod;
    ifac[k] = quickpow(fac[k]);
    for (int i = k; i >= 1; --i)
        ifac[i - 1] = ifac[i] * i % mod;
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        read(x);
        (sum += x) %= mod;
    }
    if (n == 1)
    {
        printf("%d\n", sum);
        return 0;
    }
    ll times = 0;
    for (int i = 0; i < k; ++i)
        (times += (i & 1 ? -1 : 1) * ifac[i] * ifac[k - i - 1] % mod * quickpow(k - i, n - 2) % mod * (k - i + n - 1)) %= mod;
    printf("%lld\n", (sum * times % mod + mod) % mod);
    return 0;
}