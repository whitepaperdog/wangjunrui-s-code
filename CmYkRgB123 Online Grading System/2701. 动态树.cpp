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
const int N = 2e5 + 5;
int n, m;
struct Tree
{
    int ch[2], fa;
    int sum, fakesonsize;
    bool rev;
} tree[N];
#define lc(x) tree[x].ch[0]
#define rc(x) tree[x].ch[1]
#define fa(x) tree[x].fa
inline bool nroot(int x)
{
    return lc(fa(x)) == x || rc(fa(x)) == x;
}
inline bool check(int x)
{
    return rc(fa(x)) == x;
}
inline void pushup(int x)
{
    tree[x].sum = tree[lc(x)].sum + tree[rc(x)].sum + tree[x].fakesonsize + 1;
}
inline void pushdown(int x)
{
    if (tree[x].rev)
    {
        if (lc(x))
            tree[lc(x)].rev ^= 1;
        if (rc(x))
            tree[rc(x)].rev ^= 1;
        swap(lc(x), rc(x));
        tree[x].rev = false;
    }
}
inline void rotate(int x)
{
    int y = fa(x), z = fa(y), k = check(x), w = tree[x].ch[k ^ 1];

    if (nroot(y))
        tree[z].ch[check(y)] = x;
    fa(x) = z;

    tree[x].ch[k ^ 1] = y;
    fa(y) = x;

    tree[y].ch[k] = w;
    if (w)
        fa(w) = y;

    pushup(y), pushup(x);
}
int st[N];
inline void splay(int x)
{
    int top;
    st[top = 1] = x;
    for (int y = x; nroot(y); y = fa(y))
        st[++top] = fa(y);
    while (top)
        pushdown(st[top--]);
    while (nroot(x))
    {
        if (nroot(fa(x)))
            rotate(check(fa(x)) == check(x) ? fa(x) : x);
        rotate(x);
    }
}
inline void access(int x)
{
    for (int y = 0; x; x = fa(y = x))
    {
        splay(x);
        tree[x].fakesonsize += tree[rc(x)].sum - tree[y].sum;
        rc(x) = y;
        pushup(x);
    }
}
inline int findroot(int x)
{
    access(x);
    splay(x);
    while (pushdown(x), lc(x))
        x = lc(x);
    splay(x);
    return x;
}
inline void makeroot(int x)
{
    access(x);
    splay(x);
    tree[x].rev ^= 1;
}
inline void link(int x, int y)
{
    makeroot(x), makeroot(y);
    fa(x) = y;
    tree[y].fakesonsize += tree[x].sum;
    pushup(y);
}
signed main()
{
    freopen("dynamic_tree.in", "r", stdin);
    freopen("dynamic_tree.out", "w", stdout);
    read(n, m);
    for (int i = 1; i <= n; ++i)
        pushup(i);
    while (m--)
    {
        int opt, u;
        read(opt, u);
        if (opt == 1)
            makeroot(u);
        else if (opt == 2)
        {
            access(u);
            printf("%d\n", tree[u].fakesonsize + 1);
        }
        else if (opt == 3)
        {
            int v, rt = findroot(u);
            read(v);
            link(u, v);
            makeroot(rt);
        }
    }
    return 0;
}
