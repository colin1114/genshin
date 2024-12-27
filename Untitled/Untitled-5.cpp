#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
ll n;
ll a[E], b[E];
ll dp[1001][1001];
ll ans = 1e18;
int main()
{
    memset(dp, 0x3f, sizeof dp);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 0; i <= 1000; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= 1000; j++)
        {
            if (j >= a[i])
                dp[i][j] = min(dp[i][j], dp[i - 1][j - a[i]]);
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + b[i]);
        }
    for (int i = 0; i <= 1000; i++)
        ans = min(ans, max(dp[n][i], i * 1LL));
    cout << ans;
    return 0;
}