/**
 *    unicode: UTF-8
 *    name:    爱丽丝的数位划分
 *    author:  wangjunrui (蒟蒻wjr)
 *    located: Changle District, Fuzhou City, Fujian Province, China
 *    created: 2022.09.10 周六 08:40:10 (Asia/Shanghai)
 **/
#include <cstdio>
#include <cstring>
#define ll long long
#define lll __int128
#define ull unsigned ll
#define lowbit(_x) (_x & (-_x))

//#define FAST_IO

#ifndef WIN32
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
#ifndef WIN32
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
        inline void read(char *_x)
        {
            char _s = (char)getchar();
            int _len = 0;
            while ((_s >= 0x0a && _s <= 0x0d) || (_s == 0x09) || (_s == 0x20))
                _s = (char)getchar();
            while (!((_s >= 0x0a && _s <= 0x0d) || (_s == 0x09) || (_s == 0x20)))
            {
                _x[_len++] = _s;
                _s = (char)getchar();
            }
            _x[_len] = '\0';
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
                _x = (_x << 1) + (_x << 3) + _s - '0';
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
#ifndef WIN32
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
#ifndef WIN32
#define putchar putchar_unlocked
#endif
#endif
        inline void write(char _x)
        {
            putchar(_x);
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
#ifndef WIN32
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
using namespace IO::INPUT;
using namespace IO::OUTPUT;
using namespace std;
constexpr int N = 1e3 + 5;
int n, m, a[N];
int b[N][N];
int cnt[(1 << 10) + 5];
int dp[N][N];
int where[11], _where[11];
signed main()
{
    freopen("partition.in", "r", stdin);
    freopen("partition.out", "w", stdout);
    for (int i = 1; i < (1 << 10); ++i)
        cnt[i] = cnt[i >> 1] + (i & 1);
    int T;
    read(T);
    while (T--)
    {
        read(n, m);
        for (int i = 1; i <= n; ++i)
        {
            static char s[50];
            read(s);
            a[i] = 0;
            for (int j = 0; s[j]; ++j)
                a[i] |= 1 << (s[j] - '0');
        }
        for (int i = 1; i <= n; ++i)
            for (int j = i; j <= n; ++j)
                b[i][j] = b[i][j - 1] | a[j];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 0;
        memset(where, ~0x3f, sizeof(where));
        for (int i = 1; i <= n; ++i)
        {
            memcpy(_where, where, sizeof(where));
            memset(where, ~0x3f, sizeof(where));
            for (int j = 0; j <= 10; ++j)
                if (_where[j] > 0)
                    ckmax(where[cnt[b[_where[j]][i]]], _where[j]);
            ckmax(where[cnt[b[i][i]]], i);
            memcpy(dp[i], dp[i - 1], sizeof(dp[i]));
            for (int k = 0; k <= 10; ++k)
                if (where[k] > 0)
                    for (int j = 1; j <= m; ++j)
                        ckmax(dp[i][j], dp[where[k] - 1][j - 1] + k);
        }
        write(dp[n][m], '\n');
    }
#ifdef FAST_OUT
    flush();
#endif
    return 0;
}
