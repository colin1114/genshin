#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
ll n, m, s, ans;
vector<ll> edge[E];
ll fa[E], dep[E], a[E];
ll dp[105][E];
bool vis[E];
inline void dfs(ll u, ll fa = 0)
{
    dep[u] = dep[fa] + 1;
    dp[0][u] = fa;
    for (auto v : edge[u])
        if (v != fa)
            dfs(v, u);
    return;
}
inline void init()
{
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dep[1] = 1;
    dfs(1);
    for (int i = 1; i <= 20; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = dp[i - 1][dp[i - 1][j]];

    // for (int i = 1; i <= 20; i++)
    //     for (int j = 1; j <= n; j++)
    //         // cerr << dp[i][j] << ' ';

    for (int i = 1; i < E; i++)
        fa[i] = i;
}
inline ll find(ll x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
inline void unite(ll x, ll y)
{
    fa[find(y)] = find(x);
}
inline ll lca(ll x, ll y)
{
    if (dep[x] < dep[y])
        swap(x, y);
    for (int i = 20; i >= 0; i--)
        if (dep[dp[i][x]] >= dep[y])
            x = dp[i][x];
    if (x == y)
        return x;
    for (int i = 20; i >= 0; i--)
        if (dp[i][x] != dp[i][y])
            x = dp[i][x], y = dp[i][y];
    return dp[0][x];
}
inline void dfs1(ll u, ll fa)
{
    vis[u] = 1;
    auto p = find(u), q = find(fa);
    while (p != q)
    {
        // // cerr << p << ' ' << q << endl;
        // // cerr << (p == q) << endl;
        unite(dp[0][p], p);
        p = find(p);
        vis[p] = 1;
    }
    // // cerr << endl;
}
inline ll get(ll x, ll y)
{
    return llabs(dep[x] - dep[y]);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s;
    init();
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    vis[s] = 1;
    for (int i = 1; i <= m; i++)
        if (!vis[a[i]])
        {
            // cerr << "Yes" << ' ' << s << endl;
            ll x = lca(s, a[i]);
            // cerr << "ok 1" << endl;
            ans += get(s, x);
            // cerr << "ok 2" << endl;
            ans += get(a[i], x);
            // cerr << "ok 3" << endl;
            dfs1(s, x);
            // cerr << "ok 4" << endl;
            dfs1(a[i], x);
            // cerr << "ok 5" << endl;
            s = a[i];
        }
    cout << ans;
    return 0;
}