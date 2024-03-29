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
struct Tree
{
    int sum, cnt;
} tree[N * 8];
#define lc (rt << 1)
#define rc (rt << 1 | 1)
struct node
{
    int x, y, h, v;
    node(int _x = 0, int _y = 0, int _h = 0, int _v = 0) : x(_x), y(_y), h(_h), v(_v) {}
    inline bool operator<(const node &rhs) const
    {
        return h < rhs.h;
    }
} a[N * 2];
int n, p[N * 2];
inline void pushup(int l, int r, int rt)
{
    if (tree[rt].cnt)
        tree[rt].sum = p[r + 1] - p[l];
    else if (l == r)
        tree[rt].sum = 0;
    else
        tree[rt].sum = tree[lc].sum + tree[rc].sum;
}
inline void update(int rt, int l, int r, int x, int y, int val)
{
    if (r < x || l > y)
        return;
    if (x <= l && r <= y)
    {
        tree[rt].cnt += val;
        pushup(l, r, rt);
        return;
    }
    int mid = (l + r) >> 1;
    update(lc, l, mid, x, y, val);
    update(rc, mid + 1, r, x, y, val);
    pushup(l, r, rt);
}
int cnt = 0;
signed main()
{
    read(n);
    for (int i = 1; i <= n; ++i)
    {
        int x1, y1, x2, y2;
        read(x1, y1, x2, y2);
        a[i] = node(x1, x2, y1, 1);
        a[i + n] = node(x1, x2, y2, -1);
        p[i] = x1;
        p[i + n] = x2;
    }
    n *= 2;
    sort(a + 1, a + 1 + n);
    sort(p + 1, p + 1 + n);
    cnt = (int)(unique(p + 1, p + 1 + n) - p - 1);
    ll ans = 0;
    for (int i = 1; i < n; ++i)
    {
        int l = (int)(lower_bound(p + 1, p + 1 + cnt, a[i].x) - p);
        int r = (int)(lower_bound(p + 1, p + 1 + cnt, a[i].y) - p);
        if (l < r)
            update(1, 1, cnt, l, r - 1, a[i].v);
        ans += (ll)tree[1].sum * (a[i + 1].h - a[i].h);
    }
    cout << ans << endl;
    return 0;
}
