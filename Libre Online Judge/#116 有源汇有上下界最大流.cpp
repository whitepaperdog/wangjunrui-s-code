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
const int INF = 1e9;
struct Edge
{
    int next, to, flow, cap;
} edge[N];
int head[N], num_edge = 1;
int lashead[N], lasnum_edge;
inline void add_edge(int from, int to, int cap, bool flag = true)
{
    edge[++num_edge].next = head[from];
    edge[num_edge].to = to;
    edge[num_edge].flow = 0;
    edge[num_edge].cap = cap;
    head[from] = num_edge;
    if (flag)
        add_edge(to, from, 0, false);
}
int S, T;
int dis[N], cur[N];
inline bool bfs()
{
    memset(dis, 0, sizeof(dis));
    memcpy(cur, head, sizeof(head));
    queue<int> q;
    q.push(S);
    dis[S] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = edge[i].next)
        {
            int &v = edge[i].to;
            if (!dis[v] && edge[i].cap > edge[i].flow)
            {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    return dis[T];
}
inline int dinic(int u, int flow)
{
    if (u == T)
        return flow;
    int res = 0;
    for (int &i = cur[u]; i; i = edge[i].next)
    {
        int &v = edge[i].to;
        if (dis[v] == dis[u] + 1 && edge[i].cap > edge[i].flow)
        {
            int f = dinic(v, min(flow, edge[i].cap - edge[i].flow));
            if (f)
            {
                res += f;
                flow -= f;
                edge[i].flow += f;
                edge[i ^ 1].flow -= f;
                if (!flow)
                    break;
            }
        }
    }
    return res;
}
inline int maxflow()
{
    int res = 0;
    while (bfs())
        res += dinic(S, INF);
    return res;
}
int n, m;
int out[N], in[N];
signed main()
{
    ios::sync_with_stdio(false);
    int s, t;
    read(n, m, s, t);
    for (int i = 1; i <= m; ++i)
    {
        int u, v, low, upp;
        read(u, v, low, upp);
        add_edge(u, v, upp - low);
        out[u] += low, in[v] += low;
    }
    memcpy(lashead, head, sizeof(head));
    lasnum_edge = num_edge;
    int sum = 0;
    S = 0, T = n + 1;
    for (int i = 1; i <= n; ++i)
    {
        if (in[i] == out[i])
            continue;
        if (in[i] > out[i])
        {
            add_edge(S, i, in[i] - out[i]);
            sum += in[i] - out[i];
        }
        else
            add_edge(i, T, out[i] - in[i]);
    }
    add_edge(t, s, INF);
    if (maxflow() < sum)
    {
        puts("please go home to sleep");
        return 0;
    }
    int flow = edge[num_edge ^ 1].flow;
    memcpy(head, lashead, sizeof(head));
    num_edge = lasnum_edge;
    S = s, T = t;
    printf("%d\n", maxflow() + flow);
    return 0;
}
