#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
ll n, m;
ll fa[E], dep[E];
ll dp[101][E]; // dp need [1 << n][n] (that is min).
vector<ll> edge[E];
inline void dfs(ll u, ll fa = 0)
{
    dep[u] = dep[fa] + 1;
    dp[0][u] = fa;
    for (auto v : edge[u])
        if (v != fa)
            dfs(v, u);
}
inline void init()
{
    // do something different, such as:
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    // init.
    dfs(1);
    for (int i = 1; i <= 20; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = dp[i][dp[i - 1][j]];
}
inline ll lca(ll x, ll y)
{
    // lca, can't change.
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
int main()
{
    // do something...
    return 0;
}