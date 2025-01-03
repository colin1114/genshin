#include <bits/stdc++.h>
#define endl '\n'
#define ll int

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
ll m, n;
ll x[E], y[E];
ll a[E], sum[E];
ll dp[1001][1001][101];
inline ll dfs(ll i, ll j, ll k)
{
    if (i > j)
        return 0;
    if (dp[i][j][k] != 0)
        return dp[i][j][k];
    ll res = dfs(i, j - 1, 0) + (k + 1) * (ll)(k + 1);
    for (int m = i; m < j; m++)
        if (a[m] == a[j])
        {
            ll tmp = dfs(i, m, k + 1) + dfs(m + 1, j - 1, 0);
            res = max(res, tmp);
        }
    return dp[i][j][k] = res;
}
int main()
{
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> x[i];
    for (int i = 1; i <= m; i++)
        cin >> y[i];
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (x[i] == x[j])
                sum[i] += y[j];
    memset(dp, 0xcf, sizeof dp);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= sum[i]; j++)
            dp[i][i][j] = (y[i] + j) * (y[i] + j);
    for (int len = 2; len <= n; len++)
        for (int i = 1; i + len - 1 <= n; i++)
        {
            ll j = i + len - 1;
            for (int k = 0; k <= sum[j]; k++)
                dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][0] + (y[j] + k) * (y[j] + k));
            for (int m = i; m < j; m++)
                if (x[m] == x[j])
                    for (int k = 0; k <= sum[j]; k++)
                        dp[i][j][k] = max(dp[i][j][k], dp[i][m][y[j] + k] + dp[m + 1][j - 1][0]);
        }
    cout << dp[1][n][0] << endl;
    return 0;
}