#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
ll n, k, sum;
ll fa[E], dep[E], len[E], a[E], b[E], c[E];
ll lift[21][E];
bool vis[E];
vector<PII> edge[E];
inline void dfs(ll u, ll fa = 0, ll op = 0)
{
    dep[u] = dep[fa] + 1;
    lift[0][u] = fa;
    len[u] = op;
    for (auto v : edge[u])
        if (v.x != fa)
            dfs(v.x, u, op + v.y);
}
inline bool dfs1(ll u, ll fa)
{
    bool flag = vis[u];
    for (auto v : edge[u])
        if (v.x != fa && dfs1(v.x, u))
        {
            flag = 1;
            sum += v.y;
        }
    return vis[u] = flag;
}
inline void init()
{
    dfs(1);
    for (int i = 1; i <= 20; i++)
        for (int j = 1; j <= n; j++)
            lift[i][j] = lift[i - 1][lift[i - 1][j]];
}
inline ll lca(ll x, ll y)
{
    if (dep[x] < dep[y])
        swap(x, y);
    for (int i = 20; i >= 0; i--)
        if (dep[lift[i][x]] >= dep[y])
            x = lift[i][x];
    if (x == y)
        return x;
    for (int i = 20; i >= 0; i--)
        if (lift[i][x] != lift[i][y])
            x = lift[i][x], y = lift[i][y];
    return lift[0][x];
}
inline ll dis(ll x, ll y)
{
    return len[x] + len[y] - 2 * len[lca(x, y)];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i];
        vis[a[i]] = 1;
    }
    dfs1(a[1], 0);
    ll cnt = 0;
    for (int i = 1; i <= n; i++)
        if (vis[i])
            b[++cnt] = i;
    init();
    for (int i = 1; i <= cnt; i++)
    {
        ll max1 = 0;
        for (int j = 1; j <= k; j++)
            max1 = max(max1, dis(b[i], a[j]));
        c[b[i]] = max1;
    }
    for (int i = 1; i <= n; i++)
    {
        ll ans = 1e18;
        for (int j = 1; j <= cnt; j++)
            ans = min(ans, dis(i, b[j]) - c[b[j]]);
        cout << 2 * sum + ans << endl;
    }
    return 0;
}