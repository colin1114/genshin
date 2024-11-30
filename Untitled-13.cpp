#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
ll n, m, dis[E], dep[E], st[31][E];
vector<pair<ll, ll>> vct[E];
inline void dfs(ll u, ll fa)
{
    for (auto v : vct[u])
    {
        if (v.first == fa)
            continue;
        st[0][v.first] = u;
        dep[v.first] = dep[u] + 1;
        dis[v.first] = dis[u] + v.second;
        dfs(v.first, u);
    }
}
inline ll lift(ll u, ll k)
{
    for (int i = 17; i >= 0; i--)
        if (k >> i & 1)
            u = st[i][u];
    return u;
}
inline ll lca(ll u, ll v)
{
    if (dep[u] > dep[v])
        swap(u, v);
    v = lift(v, dep[v] - dep[u]);
    if (u == v)
        return u;
    for (int i = 17; i >= 0; i--)
        if (st[i][u] != st[i][v])
            u = st[i][u], v = st[i][v];
    return st[0][u];
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        ll x, y, k;
        cin >> x >> y >> k;
        vct[x].push_back({y, k});
        vct[y].push_back({x, k});
    }
    dfs(1, 0);
    for (int i = 1; i < 18; i++)
        for (int j = 1; j <= n; j++)
            st[i][j] = st[i - 1][st[i - 1][j]];
    while (m--)
    {
        ll x, y;
        cin >> x >> y;
        ll a = lca(x, y);
        cout << dis[x] + dis[y] - 2 * dis[a] << endl;
    }
    return 0;
}