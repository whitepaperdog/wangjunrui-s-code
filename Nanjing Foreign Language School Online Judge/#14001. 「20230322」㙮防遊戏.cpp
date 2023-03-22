/**
 *    name:     A. 㙮防遊戏
 *    author:   whitepaperdog (蒟蒻wjr)
 *    located:  Xuanwu District, Nanjing City, Jiangsu Province, China
 *    created:  2023.03.22 周三 14:23:26 (Asia/Shanghai)
 *    unicode:  UTF-8
 *    standard: c++23
 **/
#include <cstdio>
#include <queue>
typedef long long ll;
typedef unsigned long long ull;
#define lowbit(x) ((x) & (-(x)))

// #define FAST_IO

#if !defined(WIN32) && !defined(_WIN32)
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif
namespace IO
{
#ifdef FAST_IO
#ifndef FAST_IN
#define FAST_IN
#endif
#ifndef FAST_OUT
#define FAST_OUT
#endif
#endif

    namespace INPUT
    {
#ifdef FAST_IN
#ifndef FAST_OUT_BUFFER_SIZE
#define FAST_OUT_BUFFER_SIZE (1 << 21)
#endif
        char _buf[FAST_OUT_BUFFER_SIZE], *_now = _buf, *_end = _buf;
#undef getchar
#define getchar() (_now == _end && (_end = (_now = _buf) + fread(_buf, 1, FAST_OUT_BUFFER_SIZE, stdin), _now == _end) ? EOF : *_now++)
#else
#if !defined(WIN32) && !defined(_WIN32)
#define getchar getchar_unlocked
#endif
#endif
        inline void read(char &_x)
        {
            char _s = (char)getchar();
            while ((_s >= 0x0a && _s <= 0x0d) || (_s == 0x09) || (_s == 0x20))
                _s = (char)getchar();
            _x = _s;
        }
        inline int read(char *_x)
        {
            char _s = (char)getchar();
            int _len = 0;
            while ((_s >= 0x0a && _s <= 0x0d) || (_s == 0x09) || (_s == 0x20))
                _s = (char)getchar();
            while (!((_s >= 0x0a && _s <= 0x0d) || (_s == 0x09) || (_s == 0x20)) && _s != EOF)
            {
                _x[_len++] = _s;
                _s = (char)getchar();
            }
            _x[_len] = '\0';
            return _len;
        }
        template <typename _T>
        inline void read(_T &_x)
        {
            _x = 0;
            char _s = (char)getchar();
            bool _f = false;
            while (!(_s >= '0' && _s <= '9'))
            {
                if (_s == '-')
                    _f = true;
                _s = (char)getchar();
            }
            while (_s >= '0' && _s <= '9')
            {
                _x = (_x << 1) + (_x << 3) + (_s - '0');
                _s = (char)getchar();
            }
            if (_f)
                _x = -_x;
        }
        template <typename _T, typename... _G>
        inline void read(_T &_x, _G &..._y)
        {
            read(_x);
            read(_y...);
        }
#ifdef FAST_IN
#undef getchar
#if !defined(WIN32) && !defined(_WIN32)
#define getchar getchar_unlocked
#endif
#endif
    }
    namespace OUTPUT
    {
#ifdef FAST_OUT
#ifndef FAST_OUT_BUFFER_SIZE
#define FAST_OUT_BUFFER_SIZE (1 << 21)
#endif
        char _buf[FAST_OUT_BUFFER_SIZE], *_now = _buf;
        inline void flush()
        {
            fwrite(_buf, 1, _now - _buf, stdout), _now = _buf;
        }
#undef putchar
#define putchar(c) (_now - _buf == FAST_OUT_BUFFER_SIZE ? flush(), *_now++ = c : *_now++ = c)
#else
#if !defined(WIN32) && !defined(_WIN32)
#define putchar putchar_unlocked
#endif
#endif
        inline void write(char _x)
        {
            putchar(_x);
        }
        inline void write(char *const _x)
        {
            for (int i = 0; _x[i]; ++i)
                putchar(_x[i]);
        }
        inline void write(const char *__restrict _x)
        {
            for (int i = 0; _x[i]; ++i)
                putchar(_x[i]);
        }
        template <typename _T>
        inline void write(_T _x)
        {
            static char dight[39];
            int _len = 0;
            if (_x == 0)
            {
                putchar('0');
                return;
            }
            bool flag = false;
            if (_x < 0)
            {
                _x = -_x;
                flag = true;
            }
            while (_x)
            {
                dight[_len++] = (char)(_x % 10) + '0';
                _x /= 10;
            }
            if (flag)
                putchar('-');
            while (_len--)
                putchar(dight[_len]);
        }
        template <typename _T, typename... _G>
        inline void write(_T _x, _G... _y)
        {
            write(_x);
            write(_y...);
        }
#ifdef FAST_OUT
#undef putchar
#if !defined(WIN32) && !defined(_WIN32)
#define putchar putchar_unlocked
#endif
#endif
    }
}
template <typename T>
inline void ckmin(T &_x, T _y)
{
    if (_x > _y)
        _x = _y;
}
template <typename T>
inline void ckmax(T &_x, T _y)
{
    if (_x < _y)
        _x = _y;
}
namespace MODINT
{
    template <const int _mod>
    struct modint
    {
        int x;
        constexpr modint(int _x = 0) : x(_x) {}
        constexpr inline modint operator+() const
        {
            return *this;
        }
        constexpr inline modint operator-() const
        {
            return !x ? 0 : _mod - x;
        }
        constexpr inline modint &operator++()
        {
            ++x;
            if (x >= _mod)
                x -= _mod;
            return *this;
        }
        constexpr inline modint &operator--()
        {
            --x;
            if (x < 0)
                x += _mod;
            return *this;
        }
        constexpr inline modint operator++(int)
        {
            int res = x;
            if (x >= _mod)
                x -= _mod;
            return res;
        }
        constexpr inline modint operator--(int)
        {
            int res = x;
            if (x < 0)
                x += _mod;
            return res;
        }
        constexpr inline modint operator+(const modint &rhs) const
        {
            int res = x;
            res += rhs.x;
            if (res >= _mod)
                res -= _mod;
            return res;
        }
        constexpr inline modint operator-(const modint &rhs) const
        {
            int res = x;
            res -= rhs.x;
            if (res < 0)
                res += _mod;
            return res;
        }
        constexpr inline modint operator*(const modint &rhs) const
        {
            return (int)((ll)x * rhs.x % _mod);
        }
        constexpr inline modint &operator+=(const modint &rhs)
        {
            x += rhs.x;
            if (x >= _mod)
                x -= _mod;
            return *this;
        }
        constexpr inline modint &operator-=(const modint &rhs)
        {
            x -= rhs.x;
            if (x < 0)
                x += _mod;
            return *this;
        }
        constexpr inline modint &operator*=(const modint &rhs)
        {
            x = (int)((ll)x * rhs.x % _mod);
            return *this;
        }
        template <typename _G>
        constexpr inline modint operator^(_G rhs) const
        {
            modint a = x, res = 1;
            while (rhs)
            {
                if (rhs & 1)
                    res *= a;
                a *= a;
                rhs >>= 1;
            }
            return res;
        }
        constexpr inline modint inv() const
        {
            return *this ^ (_mod - 2);
        }
        constexpr inline modint operator/(const modint &rhs) const
        {
            return (*this) * rhs.inv();
        }
        constexpr inline modint &operator/=(const modint &rhs)
        {
            return (*this) *= rhs.inv();
        }
        constexpr inline bool operator==(const modint &rhs) const
        {
            return x == rhs.x;
        }
        constexpr inline bool operator!=(const modint &rhs) const
        {
            return x != rhs.x;
        }
        constexpr inline int &data()
        {
            return x;
        }
    };
}
using IO::INPUT::read;
using IO::OUTPUT::write;
using namespace std;
constexpr int N = 50 * 50 * 2 + 5;
constexpr int INF = 0x7fffffff;
int n, m, a[N][N];
struct Edge
{
    int next, to, flow, cap;
} edge[N * 114];
int head[N], num_edge = 1;
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
int S, T, ST;
int cur[N], dis[N];
bool exist[N];
inline bool bfs()
{
    for (int i = S; i <= T; ++i)
    {
        dis[i] = exist[i] = 0;
        cur[i] = head[i];
    }
    queue<int> q;
    q.push(S);
    dis[S] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].to;
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
    exist[u] = true;
    int res = 0;
    for (int &i = cur[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (!exist[v] && dis[v] == dis[u] + 1 && edge[i].cap > edge[i].flow)
        {
            int f = dinic(v, min(flow, edge[i].cap - edge[i].flow));
            if (f)
            {
                edge[i].flow += f;
                edge[i ^ 1].flow -= f;
                res += f;
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
inline int mincut()
{
    int res = 0;
    while (bfs())
        res += dinic(S, INF);
    return res;
}
int id[N][N], tot;
signed main()
{
#ifdef PAPERDOG
    freopen("project.in", "r", stdin);
    freopen("project.out", "w", stdout);
#else
    freopen("dafangyouxi.in", "r", stdin);
    freopen("dafangyouxi.out", "w", stdout);
#endif
    read(n, m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            read(a[i][j]);
    S = 0, T = 2 * n * m + 1;
    auto calc = [](int x, int y)
    {
        return (x - 1) * m + y;
    };
    int sum = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            add_edge(calc(i, j), calc(i, j) + n * m, INF);
            if (!a[i][j])
                continue;
            if (a[i][j] == -1)
            {
                int maxx = 0;
                for (int x = i - 1, y = j; x >= 1; --x)
                {
                    add_edge(calc(x, y), calc(x + 1, y), INF);
                    int res = max(a[x][y], maxx);
                    add_edge(S, calc(x, y), res - maxx);
                    sum += res - maxx;
                    maxx = res;
                }
            }
            else if (a[i][j] == -2)
            {
                int maxx = 0;
                for (int x = i + 1, y = j; x <= n; ++x)
                {
                    add_edge(calc(x, y), calc(x - 1, y), INF);
                    int res = max(a[x][y], maxx);
                    add_edge(S, calc(x, y), res - maxx);
                    sum += res - maxx;
                    maxx = res;
                }
            }
            else if (a[i][j] == -3)
            {
                int maxx = 0;
                for (int x = i, y = j - 1; y >= 1; --y)
                {
                    add_edge(calc(x, y + 1) + n * m, calc(x, y) + n * m, INF);
                    int res = max(a[x][y], maxx);
                    add_edge(calc(x, y) + n * m, T, res - maxx);
                    sum += res - maxx;
                    maxx = res;
                }
            }
            else if (a[i][j] == -4)
            {
                int maxx = 0;
                for (int x = i, y = j + 1; y <= m; ++y)
                {
                    add_edge(calc(x, y - 1) + n * m, calc(x, y) + n * m, INF);
                    int res = max(a[x][y], maxx);
                    add_edge(calc(x, y) + n * m, T, res - maxx);
                    sum += res - maxx;
                    maxx = res;
                }
            }
        }
    write(sum - mincut(), '\n');
#ifdef FAST_OUT
    IO::OUTPUT::flush();
#endif
    return 0;
}