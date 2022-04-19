#include <cstdio>
#include <random>
#define ll long long
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
constexpr int N = 1e5 + 5;
mt19937 rnd((random_device())());
signed main()
{
    freopen("project.in", "w", stdout);
    uniform_int_distribution<int> dis(0, 2e5);
    printf("10000\n");
    for (int i = 1; i <= 200; ++i)
    {
        int l = dis(rnd), r = dis(rnd);
        if (l > r)
            swap(l, r);
        printf("%d %d\n", l, r);
    }
    return 0;
}