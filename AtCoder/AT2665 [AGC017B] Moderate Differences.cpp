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
int n, A, B, C, D;
signed main()
{
    read(n, A, B, C, D);
    for (int i = 0; i < n; ++i)
    {
        ll res = B + (ll)(n - 1 - 2 * i) * C;
        if (res >= A - (ll)(n - 1 - i) * (D - C) && res <= A + (ll)i * (D - C))
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
