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
constexpr int N = 405, M = 1e5 + 5;
int n, m;
int a[M], b[M];
bitset<N> cant, status[N];
signed main()
{
    read(n, m);
    for (int i = 1; i <= m; ++i)
        read(a[i], b[i]);
    for (int S = 1; S <= n; ++S)
    {
        status[S].set(S);
        for (int i = m; i >= 1; --i)
        {
            if (status[S][a[i]] && status[S][b[i]])
            {
                cant.set(S);
                break;
            }
            else if (status[S][a[i]])
                status[S].set(b[i]);
            else if (status[S][b[i]])
                status[S].set(a[i]);
        }
    }
    int res = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (cant[i])
            continue;
        for (int j = i + 1; j <= n; ++j)
        {
            if (cant[j])
                continue;
            if (!(status[i] & status[j]).any())
                ++res;
        }
    }
    printf("%d\n", res);
    return 0;
}