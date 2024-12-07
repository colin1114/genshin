#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
ll n, m, s, t;
ll x, y, w;
ll dis[E], vis[E];
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
vector<pair<ll, ll>> e[E];
inline void dijkstra()
{
    memset(dis, 0x3f, sizeof dis);
    dis[s] = 0;
    q.push({0, s});
    while (!q.empty())
    {
        ll x = q.top().second;
        q.pop();
        if (vis[x])
            continue;
        vis[x] = 1;
        for (auto i : e[x])
        {
            dis[i.first] = min(dis[i.first], dis[x] + i.second);
            if (vis[i.first])
                continue;
            q.push({i.second + dis[x], i.first});
        }
    }
}
int main()
{
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> w;
        e[x].push_back({y, w});
        e[y].push_back({x, w});
    }
    dijkstra();
    cout << dis[t];
    return 0;
}