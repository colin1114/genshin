#include <bits/stdc++.h>
#define ll int
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
ll n, p;
ll in[E];
vector<ll> edge[E];
ll dp[3001][3001];
inline void dfs(ll u, ll fa)
{
    dp[u][1] = in[u];
    for (auto v : edge[u])
        if (v != fa)
        {
            dfs(v, u);
            for (int i = p; i >= 1; i--)
                for (int j = 1; j < i; j++)
                    dp[u][i] = min(dp[u][i], dp[u][j] + dp[v][i - j] - 2);
        }
}
int main()
{
    cin >> n >> p;
    for (int i = 1; i < n; i++)
    {
        ll u, v;
        cin >> u >> v;
        in[u]++;
        in[v]++;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    memset(dp, 0x3f, sizeof dp);
    dfs(1, 0);
    ll ans = 1e18;
    for (int i = 1; i <= n; i++)
        ans = min(ans, dp[i][p]);
    cout << ans;
    return 0;
}