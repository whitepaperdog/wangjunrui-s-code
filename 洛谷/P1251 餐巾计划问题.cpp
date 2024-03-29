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
inline void clear(T *a, int l, int r, int val)
{
    memset(&a[l], val, sizeof(T) * (r - l + 1));
}
const int N = 1e6 + 5, INF = 0x3f3f3f3f;
int n;
int w[N];
struct Edge
{
    int next, to, cap, flow, cost;
} edge[N];
int head[N], num_edge = 1;
inline void add_edge(int from, int to, int cap, int cost, bool flag = true)
{
    edge[++num_edge].next = head[from];
    edge[num_edge].to = to;
    edge[num_edge].cap = cap;
    edge[num_edge].flow = 0;
    edge[num_edge].cost = cost;
    head[from] = num_edge;
    if (flag)
        add_edge(to, from, 0, -cost, false);
}
#define s 0
#define t (2 * n + 1)
int dis[N], cur[N];
bool exist[N];
inline bool spfa()
{
    clear(dis, s, t, INF);
    clear(exist, s, t, 0);
    for (re int i = s; i <= t; ++i)
        cur[i] = head[i];
    std::queue<int> q;
    q.push(s);
    exist[s] = true;
    dis[s] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        exist[u] = false;
        for (re int i = head[u]; i; i = edge[i].next)
        {
            int &v = edge[i].to;
            if (dis[v] > dis[u] + edge[i].cost && edge[i].cap > edge[i].flow)
            {
                dis[v] = dis[u] + edge[i].cost;
                if (!exist[v])
                {
                    exist[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return dis[t] < INF;
}
ll ans = 0;
inline int dinic(int u, int flow)
{
    if (u == t)
    {
        ans += (ll)flow * dis[t];
        return flow;
    }
    int res = 0;
    exist[u] = true;
    for (int &i = cur[u]; i; i = edge[i].next)
    {
        int &v = edge[i].to;
        if (!exist[v] && dis[v] == dis[u] + edge[i].cost && edge[i].cap > edge[i].flow)
        {
            int f = dinic(v, std::min(flow, edge[i].cap - edge[i].flow));
            if (f)
            {
                res += f;
                edge[i].flow += f;
                edge[i ^ 1].flow -= f;
                flow -= f;
                if (!flow)
                {
                    exist[u] = false;
                    break;
                }
            }
        }
    }
    return res;
}
signed main()
{
    int f, a, b, fa, fb;
    read(n);
    for (re int i = 1; i <= n; ++i)
        read(w[i]);
    read(f, a, fa, b, fb);
    for (re int i = 1; i <= n; ++i)
    {
        add_edge(s, i, w[i], f);
        add_edge(i, t, w[i], 0);
        add_edge(s, i + n, w[i], 0);
        if (i < n)
            add_edge(i + n, i + 1 + n, INF, 0);
        if (i <= n - a)
            add_edge(i + n, i + a, INF, fa);
        if (i <= n - b)
            add_edge(i + n, i + b, INF, fb);
    }
    while (spfa())
        dinic(s, INF);
    printf("%lld\n", ans);
    return 0;
}
