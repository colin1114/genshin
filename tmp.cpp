#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 2e6 + 5;
ll n, q;
vector<ll> edge[E];
vector<PII> edge1[E];
ll fa[E], ans[E];
bool vis[E];
inline ll find(ll x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
inline void unite(ll x, ll y)
{
    if (find(x) == find(y))
        return;
    fa[find(y)] = find(x);
}
inline void dfs(ll u, ll fa)
{
    for (auto v : edge[u])
    {
        if (v == fa)
            continue;
        dfs(v, u);
        unite(u, v);
    }
    vis[u] = 1;
    for (auto v : edge1[u])
        if (vis[v.x])
            ans[v.y] = find(v.x);
}
int main()
{
    cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    for (int i = 1; i <= q; i++)
    {
        ll x, y;
        cin >> x >> y;
        edge1[x].push_back({y, i});
        edge1[y].push_back({x, i});
    }
    for (int i = 1; i <= 2e6; i++)
        fa[i] = i;
    dfs(1, 0);
    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
    return 0;
}