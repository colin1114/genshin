#include <bits/stdc++.h>
#define ll long long

#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
ll n, m;
ll a[1001][1001];
ll dp[1001][1001];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            ll ans = 0;
            for (int k = 0; k <= j; k++)
                ans = max(ans, dp[i - 1][k] + a[i][j - k]);
            dp[i][j] = ans;
        }
    cout << dp[n][m];
    return 0;
}