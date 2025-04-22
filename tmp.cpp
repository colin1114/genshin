#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) x.begin(), x.end()
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ull = unsigned long long;
using db = double;
using i128 = __int128_t;
constexpr int inf = 1e9 + 7;
constexpr ll INF = 1e18 + 14;
constexpr int mod = 998244353;
constexpr int maxn = 5e5 + 100;
constexpr int maxm = 1e6 + 100;

ll inv2, inv3;

inline char get(void)
{
    static char buf[1 << 19], *p1 = buf, *p2 = buf;
    if (p1 == p2)
    {
        p2 = (p1 = buf) + fread(buf, 1, 1 << 19, stdin);
        if (p1 == p2)
            return EOF;
    }
    return *p1++;
}

template <typename T>
inline void read(T &x)
{
    x = 0;
    static char c;
    bool minus = false;
    for (; !(c >= '0' && c <= '9'); c = get())
        if (c == '-')
            minus = true;
    for (; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = get())
        ;
    if (minus)
        x = -x;
}

template <typename T>
void add(T &x, const T &y)
{
    if ((x += y) >= mod)
        x -= mod;
}
template <typename T>
void dec(T &x, const T &y)
{
    if ((x -= y) < 0)
        x += mod;
}
template <typename T>
void cmax(T &x, const T &y)
{
    if (y > x)
        x = y;
}
template <typename T>
void cmin(T &x, const T &y)
{
    if (y < x)
        x = y;
}

ll qpow(ll x, ll a)
{
    ll base = x, rt = 1;
    while (a)
    {
        if (a & 1)
            rt *= base, rt %= mod;
        base *= base, base %= mod;
        a >>= 1;
    }
    return rt;
}

ll inv(ll a)
{
    if (a < 0)
        a += mod;
    return qpow(a, mod - 2);
}

int lowbit(int x)
{
    return x & (-x);
}

ll lcm(ll a, ll b)
{
    ll g = __gcd(a, b);
    return a / g * b;
}

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

vector<ll> fac, ifac;

void init_fac()
{
    fac.resize(maxn), ifac.resize(maxn);
    fac[0] = fac[1] = 1;
    for (int i = 2; i < maxn; i++)
        fac[i] = fac[i - 1] * i % mod;
    ifac[maxn - 1] = inv(fac[maxn - 1]);
    for (int i = maxn - 2; i >= 0; i--)
        ifac[i] = ifac[i + 1] * (i + 1) % mod;
}

ll C(int n, int m)
{
    return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

vector<int> prime, np, divi;

void init_prime()
{
    np.resize(maxm);
    divi.resize(maxm);
    for (int i = 2; i < maxm; i++)
    {
        if (!np[i])
        {
            prime.push_back(i);
            divi[i] = i;
        }
        for (auto v : prime)
        {
            if (v * i >= maxm)
                break;
            np[v * i] = 1;
            divi[v * i] = v;
            if (i % v == 0)
                break;
        }
    }
}

void init()
{
    // init_fac();
    // init_prime();
}

namespace sgt
{

    int n;
    static constexpr int rt = 1;
    static constexpr int sz = 5;

    struct Node
    {
        int a, b;
        array<array<ll, 5>, 5> dp;

        void init()
        {
            for (auto &arr : dp)
                fill(all(arr), -INF);
            dp[0][0] = dp[2][2] = dp[4][4] = 0;
            dp[1][1] = dp[3][3] = a;
            dp[0][1] = dp[1][2] = dp[2][3] = dp[3][4] = a + b;
            dp[0][2] = dp[2][4] = a + 2ll * b;
        }

        Node()
        {
            for (auto &arr : dp)
                fill(all(arr), -INF);
            dp[0][0] = dp[2][2] = dp[4][4] = 0;
        }

        Node(int _a, int _b)
        {
            a = _a;
            b = _b;
            init();
        }
    };

    vector<Node> t;

    Node merge(const Node &u, const Node &v)
    {
        Node ret;
        for (int i = 0; i < sz; i++)
            for (int j = i; j < sz; j++)
                for (int k = j; k < sz; k++)
                {
                    // cerr << format("<{}, {}, {}> {} {}", i, j, k, u.dp[i][j], v.dp[j][k]) << endl;
                    cmax(ret.dp[i][k], u.dp[i][j] + v.dp[j][k]);
                }
        return ret;
    }

    void build(const vector<int> &a, const vector<int> &b, int p, int cl = 0, int cr = n - 1)
    {
        if (cl == cr)
        {
            t[p] = Node(a[cl], b[cl]);
            return;
        }
        auto lc = p << 1, rc = lc + 1, mid = (cl + cr) >> 1;
        build(a, b, lc, cl, mid);
        build(a, b, rc, mid + 1, cr);
        t[p] = merge(t[lc], t[rc]);
    }

    void init(const vector<int> &a, const vector<int> &b)
    {
        n = a.size();
        t.resize(n << 2);
        build(a, b, rt);
    }

    Node qry(int l, int r, int p = rt, int cl = 0, int cr = n - 1)
    {
        if (cl > r || cr < l)
            return Node();
        if (cl >= l && cr <= r)
            return t[p];
        auto lc = p << 1, rc = lc + 1, mid = (cl + cr) >> 1;
        return merge(qry(l, r, lc, cl, mid), qry(l, r, rc, mid + 1, cr));
    }

    void modify(int type, int pos, int v, int p = rt, int cl = 0, int cr = n - 1)
    {
        if (pos > cr || pos < cl)
            return;
        // cerr << cl << ' ' << cr << endl;
        if (cl == cr && pos == cl)
        {
            if (type == 1)
                t[p].a = v;
            else
                t[p].b = v;
            t[p].init();
            return;
        }
        auto lc = p << 1, rc = lc + 1, mid = (cl + cr) >> 1;
        modify(type, pos, v, lc, cl, mid);
        modify(type, pos, v, rc, mid + 1, cr);
        t[p] = merge(t[lc], t[rc]);
    }

}

void solve()
{
    int n;
    cin >> n;
    vector a(n, 0), b(n, 0);
    for (auto &v : a)
        cin >> v;
    for (auto &v : b)
        cin >> v;
    sgt::init(a, b);

    int q;
    cin >> q;
    while (q--)
    {
        int type, p, x;
        cin >> type >> p >> x;
        if (type == 3)
        {
            auto res = sgt::qry(p - 1, x - 1);
            cout << res.dp[0][4] << '\n';
        }
        else
            sgt::modify(type, p - 1, x);
    }
}

int main()
{
// cerr << inv(2) << endl;
// clock_t st = clock(), ed;
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("my.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // srand(114514);
    init();
    int t = 1;
    cout << setprecision(6) << fixed;
    cerr << setprecision(2) << fixed;
    // cin >> t;
    // read(t);
    while (t--)
    {
        solve();
    }
    cout.flush();
    cerr.flush();
    // ed = clock();
    // double endtime=(double)(ed-st)/CLOCKS_PER_SEC;
    // cerr<<"Total time:"<<endtime<<endl;
    // system("pause");
    return 0;
}   