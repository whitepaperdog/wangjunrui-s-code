/**
 *    unicode: UTF-8
 *    name:    #1352. 【20省选集训day4】GCD再放送
 *    author:  wangjunrui (蒟蒻wjr)
 *    located: Changle District, Fuzhou City, Fujian Province, China
 *    created: 2022.12.20 周二 10:21:15 (Asia/Shanghai)
 **/
#include <algorithm>
#include <cstdio>
#include <vector>
#define ll long long
#define lll __int128
#define ull unsigned ll
#define lowbit(_x) (_x & (-_x))

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
template <typename _T, const _T _mod>
struct modint
{
	_T x;
	modint(_T _x = 0) : x(_x) {}
	inline modint operator+(const modint &rhs) const
	{
		_T res = x;
		res += rhs.x;
		if (res >= _mod)
			res -= _mod;
		return res;
	}
	inline modint operator-(const modint &rhs) const
	{
		_T res = x;
		res -= rhs.x;
		if (res < 0)
			res += _mod;
		return res;
	}
	inline modint operator*(const modint &rhs) const
	{
		return (_T)((ll)x * rhs.x % _mod);
	}
	inline modint &operator+=(const modint &rhs)
	{
		x += rhs.x;
		if (x >= _mod)
			x -= _mod;
		return *this;
	}
	inline modint &operator-=(const modint &rhs)
	{
		x -= rhs.x;
		if (x < 0)
			x += _mod;
		return *this;
	}
	inline modint &operator*=(const modint &rhs)
	{
		x = (_T)((ll)x * rhs.x % _mod);
		return *this;
	}
	template <typename _G>
	inline modint operator^(_G rhs) const
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
	inline modint inv()
	{
		return this->pow(_mod - 2);
	}
	inline modint operator/(const modint &rhs) const
	{
		return (*this) * rhs.inv();
	}
	inline modint &operator/=(const modint &rhs)
	{
		return (*this) *= rhs.inv();
	}
	inline modint &operator==(const modint &rhs)
	{
		return x == rhs.x;
	}
	inline _T &data()
	{
		return x;
	}
};
template <typename _T, const int MAXN, const int MAXM>
struct Graph
{
	struct Edge
	{
		int next;
		_T to;
	} edge[MAXM];
	int head[MAXN], num_edge;
	inline void add_edge(int from, _T to)
	{
		edge[++num_edge].next = head[from];
		edge[num_edge].to = to;
		head[from] = num_edge;
	}
#define foreach(i, graph, u) for (int i = graph.head[u]; i; i = graph.edge[i].next)
};
using IO::INPUT::read;
using IO::OUTPUT::write;
using namespace std;
constexpr int N = 1e5 + 5;
constexpr int mod = 1e9 + 7;
typedef modint<int, mod> node;
int n, m;
vector<int> f[N];
int pre[N], suf[N], all[N];
node g[N], h[N];
int p[N], tot;
int mp[N];
node dp[N];
node fac[N], ifac[N];
inline node quickpow(node _a, int _b)
{
	node res = 1;
	while (_b)
	{
		if (_b & 1)
			res *= _a;
		_a *= _a;
		_b >>= 1;
	}
	return res;
}
node pwp[N];
signed main()
{
//	freopen("project.in", "r", stdin);
//	freopen("project.out", "w", stdout);
	for (int i = 1; i <= (int)1e5; ++i)
		for (int j = i; j <= (int)1e5; j += i)
			f[j].push_back(i);
	read(n);
	for (int i = 1; i <= n; ++i)
	{
		int gcd = 0;
		read(tot);
		for (int j = 1; j <= tot; ++j)
		{
			read(p[j]);
			gcd = __gcd(gcd, p[j]);
			ckmax(m, p[j]);
		}
		
		for (auto j : f[gcd])
		{
			++all[j];
			h[j] += g[j] * tot;
			g[j] += tot;
		}
		
		int qwq = 0;
		for (int j = 1; j <= tot; ++j)
		{
			qwq = __gcd(qwq, p[j]);
			for (auto k : f[qwq])
				if (gcd % k)
					pwp[k] += suf[k];
		}
		
		qwq = 0;
		for (int j = tot; j >= 1; --j)
		{
			qwq = __gcd(qwq, p[j]);
			for (auto k : f[qwq])
				if (gcd % k)
					pwp[k] += pre[k];
		}
		qwq = 0;
		for (int j = 1; j <= tot; ++j)
		{
			qwq = __gcd(qwq, p[j]);
			for (auto k : f[qwq])
				if (gcd % k)
					++pre[k];
		}
		
		qwq = 0;
		for (int j = tot; j >= 1; --j)
		{
			qwq = __gcd(qwq, p[j]);
			for (auto k : f[qwq])
				if (gcd % k)
					++suf[k];
		}
		
		for (int j = 1; j <= tot; ++j)
		{
			for (auto k : f[p[j - 1]])
				if (p[j] % k)
					mp[k] = 0;
			for (auto k : f[p[j]])
				dp[k] += ++mp[k];
		}
		for (auto k : f[p[tot]])
			mp[k] = 0;
	}
	fac[0] = 1;
	for (int i = 1; i <= n; ++i)
		fac[i] = fac[i - 1] * i;
	ifac[n] = quickpow(fac[n], mod - 2);
	for (int i = n; i >= 1; --i)
		ifac[i - 1] = ifac[i] * i;
	auto A = [](int _n, int _m)
	{
		return fac[_n] * ifac[_n - _m];
	};
	node answer = 0;
	for (int i = m; i >= 1; --i)
	{
		dp[i] *= fac[n];
		if (pwp[i].data())
			for (int j = 0; j <= all[i]; ++j)
				dp[i] += A(all[i], j) * pwp[i] * fac[n - j - 1];
		for (int j = 0; j <= all[i] - 1; ++j)
			dp[i] += A(all[i] - 1, j) * (pre[i] + suf[i]) * g[i] * fac[n - j - 1];
		for (int j = 0 ; j <= all[i] - 2; ++j)
			dp[i] += A(all[i] - 2, j) * h[i] * 2 * fac[n - j - 1];
		for (int j = i + i; j <= m; j += i)
			dp[i] -= dp[j];
		answer += dp[i] * i;
	}
	write(answer.data(), '\n');
#ifdef FAST_OUT
	IO::OUTPUT::flush();
#endif
	return 0;
}