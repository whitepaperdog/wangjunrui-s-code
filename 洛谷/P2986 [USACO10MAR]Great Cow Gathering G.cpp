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
const int N = 1e5 + 5;
struct Edge
{
    int next, to, dis;
} edge[N * 2];
int head[N], num_edge;
inline void add_edge(int from, int to, int dis)
{
    edge[++num_edge].next = head[from];
    edge[num_edge].to = to;
    edge[num_edge].dis = dis;
    head[from] = num_edge;
}
int n, a[N];
int cnt[N];
ll f[N], g[N];
inline void dfs1(int u, int _fa)
{
    cnt[u] = a[u];
    for (int i = head[u]; i; i = edge[i].next)
    {
        int &v = edge[i].to;
        if (v == _fa)
            continue;
        dfs1(v, u);
        cnt[u] += cnt[v];
        f[u] += f[v] + (ll)edge[i].dis * cnt[v];
    }
}
inline void dfs2(int u, int _fa)
{
    for (int i = head[u]; i; i = edge[i].next)
    {
        int &v = edge[i].to;
        if (v == _fa)
            continue;
        g[v] = g[u] + (ll)edge[i].dis * (cnt[1] - cnt[v]) - (ll)edge[i].dis * cnt[v];
        dfs2(v, u);
    }
}
signed main()
{
    read(n);
    for (int i = 1; i <= n; ++i)
        read(a[i]);
    for (int i = 1; i < n; ++i)
    {
        int u, v, w;
        read(u, v, w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    dfs1(1, 0);
    g[1] = f[1];
    dfs2(1, 0);
    //	for(int i=1; i<=n; ++i)
    //		printf("%lld ",f[i]);
    //	putchar('\n');
    //	for(int i=1; i<=n; ++i)
    //		printf("%lld ",g[i]);
    //	putchar('\n');
    ll ans = 1e18;
    for (int i = 1; i <= n; ++i)
        ans = min(ans, g[i]);
    printf("%lld\n", ans);
    return 0;
}
