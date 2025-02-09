#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
ll n, ans;
vector<ll> edge[E];
ll dp[E];
inline void dfs(ll u, ll fa)
{
    for (auto v : edge[u])
        if (v != fa)
        {
            dfs(v, u);
            ans = max(ans, dp[u] + dp[v] + 1);
            dp[u] = max(dp[u], dp[v] + 1);
        }
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        ll u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans;
    return 0;
}