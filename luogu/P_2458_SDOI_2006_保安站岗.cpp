#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;
const int E = 1e6 + 5;
ll n;
ll dp[E][3];
vector<ll> edge[E];
inline void dfs(ll x, ll fa)
{
    dp[x][0] = 0;
    dp[x][1] = 1;
    dp[x][2] = 0;
    ll min1 = 1e18;
    for (auto u : edge[x])
    {
        if (u == fa)
            continue;
        dfs(u, x);
        dp[x][0] += dp[u][2];
        dp[x][1] += min(dp[u][0], min(dp[u][1], dp[u][2]));
        dp[x][2] += min(dp[u][1], dp[u][2]);
        min1 = min(min1, max(0ll, dp[u][1] - dp[u][2]));
    }
    dp[x][2] = 1e18;
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
    cout << min(dp[1][1], dp[1][2]);
    return 0;
}