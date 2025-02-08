#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
ll n;
vector<PII> edge[E];
PII dis[E];
ll df[E];
inline void change(ll u, ll v)
{
    if (dis[u].x < v)
        swap(dis[u].x, v);
    if (dis[u].y < v)
        swap(dis[u].y, v);
}
inline void dfs(ll u, ll fa)
{
    for (auto v : edge[u])
        if (v.x != fa)
            dfs(v.x, u), change(u, dis[v.x].x + v.y);
    if (dis[u].x == -1e18)
        dis[u].x = 0;
}
inline void dfs1(ll u, ll fa)
{
    for (auto v : edge[u])
        if (v.x != fa)
        {
            df[v.x] = max(df[v.x], df[u] + v.y);
            if (dis[u].x != v.y + dis[v.x].x)
                df[v.x] = max(df[v.x], v.y + dis[u].x);
            else
                df[v.x] = max(df[v.x], v.y + dis[u].y);
            dfs1(v.x, u);
        }
}
int main()
{
    cin >> n;
    for (int i = 0; i <= 1e6; i++)
        dis[i] = {-1e18, -1e18};
    for (int i = 1; i < n; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        edge[x].push_back({y, z});
        edge[y].push_back({x, z});
    }
    dfs(1, 0);
    dfs1(1, 0);
    ll ans = 1e18;
    for (int i = 1; i <= n; i++)
        ans = min(ans, max(dis[i].x, df[i]));
    cout << ans;
    return 0;
}