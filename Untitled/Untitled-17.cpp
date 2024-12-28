#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
ll b, e, p, n, m;
vector<ll> edge[E];
ll ans1[20][E];
queue<PII> que;
inline void init(ll x, ll st, ll id)
{
    if (ans1[id][x] != -1)
        return;
    ans1[id][x] = st;
    que.push({x, st});
}
inline void bfs(ll x, ll id)
{
    for (int i = 1; i <= n; i++)
        ans1[id][i] = -1;
    init(x, 0, id);
    while (!que.empty())
    {
        auto [p, q] = que.front();
        que.pop();  
        for (auto v : edge[p])
            init(v, q + 1, id);
    }
}
int main()
{
    cin >> b >> e >> p >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    bfs(1, 0);
    bfs(2, 1);
    bfs(n, 2);
    ll ans = 1e18;
    for (int i = 1; i <= n; i++)
    {
        auto u = ans1[0][i], v = ans1[1][i], w = ans1[2][i];
        ans = min(ans, u * b + v * e + w * p);
    }
    cout << ans;
    return 0;
}