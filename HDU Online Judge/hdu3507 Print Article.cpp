#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define re register
#define ll long long
#define ull unsigned long long
#define rep(i, a, b) for (re int i = a; i <= b; ++i)
#define per(i, a, b) for (re int i = a; i >= b; --i)
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
inline void clear(T *array, int l, int r, int val)
{
    memset(&array[l], val, sizeof(T) * (r - l + 1));
}
using namespace std;
const int N = 5e5 + 5;
int n, m;
ll sum[N];
ll dp[N];
int q[N];
#define g(x) (dp[x] + sum[x] * sum[x])
signed main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        for (int i = 1; i <= n; ++i)
        {
            int x;
            read(x);
            sum[i] = sum[i - 1] + x;
        }
        int head = 1, tail = 1;
        q[1] = 0;
        for (int i = 1; i <= n; ++i)
        {
            while (head < tail && (g(q[head + 1]) - g(q[head])) <= 2 * sum[i] * (sum[q[head + 1]] - sum[q[head]]))
                ++head;
            dp[i] = dp[q[head]] + (sum[i] - sum[q[head]]) * (sum[i] - sum[q[head]]) + m;
            while (head < tail && (g(q[tail]) - g(q[tail - 1])) * (sum[i] - sum[q[tail]]) >= (g(i) - g(q[tail])) * (sum[q[tail]] - sum[q[tail - 1]]))
                --tail;
            q[++tail] = i;
        }
        printf("%lld\n", dp[n]);
    }

    return 0;
}
