#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
ll n, max1 = -1, max1id;
ll dis[E];
vector<ll> edge[E];
inline void dfs(ll u, ll fa)
{
    dis[u] = dis[fa] + 1;
    if (max1 == -1 || dis[u] > max1)
        max1 = dis[u], max1id = u;
    for (auto v : edge[u])
        if (v != fa)
            dfs(v, u);
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs(1, 0);
    max1 = -1;
    memset(dis, 0, sizeof dis);
    dfs(max1id, 0);
    cout << dis[max1id] - 1;
    return 0;
}