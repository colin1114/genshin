#include <bits/stdc++.h>
#define ll long long

#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
ll n, q, cnt;
vector<ll> edge[E];
ll in[E], out[E];
ll dp[101][E];
inline void dfs(ll x, ll p = 0)
{
    in[x] = ++cnt;
    dp[0][x] = p;
    for (int i = 1; i <= 20; i++)
        dp[i][x] = dp[i - 1][dp[i - 1][x]];
    for (auto u : edge[x])
    {
        if (u == p)
            continue;
        dfs(u, x);
    }
    out[x] = ++cnt;
}
inline bool check(ll x, ll y)
{
    return in[x] <= in[y] && out[x] >= out[y];
}
inline ll LCA(ll a, ll b)
{
    if (check(a, b))
        return a;
    if (check(b, a))
        return b;
    for (int i = 20; i >= 0; i--)
    {
        if (dp[i][a] == 0)
            continue;
        if (!check(dp[i][a], b))
            a = dp[i][a];
    }
    return dp[0][a];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 2; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs(1);
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        cout << LCA(x, y) << endl;
    }
    return 0;
}