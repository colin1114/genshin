#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;
const int E = 1e6 + 5;
ll n;
ll dp[E][3];
vector<ll> edge[E];
inline void dfs(ll u, ll fa)
{
    dp[u][0] = 0;
    dp[u][1] = 1;
    dp[u][2] = 0;
    ll min1 = 1e18;
    for (auto v : edge[u])
    {
        if (v == fa)
            continue;
        dfs(v, u);
        dp[u][0] += dp[v][2];
        dp[u][1] += min(dp[v][0], min(dp[v][1], dp[v][2]));
        dp[u][2] += min(dp[v][1], dp[v][2]);
        min1 = min(min1, max(0ll, dp[v][1] - dp[v][2]));
    }
    dp[u][2] += min1;
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