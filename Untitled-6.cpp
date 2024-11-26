#include <bits/stdc++.h>
#define ll long long

#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
ll a, b, c, p1, p2, p3, n;
ll t[E];
ll dp[20][200][200];
int main()
{
    auto calc = [&](ll x, ll y, ll z) -> ll
    {
        return min({x / a, y / b, z / c});
    };
    memset(dp, -1, sizeof dp);
    cin >> a >> b >> c;
    cin >> p1 >> p2 >> p3;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> t[i];
    ll tot = calc(100, 100, 100);
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= tot * a; j++)
            for (int k = 0; k <= tot * b; k++)
                for (int p = 0; p <= j; p++)
                    for (int q = 0; q <= k; q++)
                    {
                        ll cur = t[i] - p1 * p - p2 * q;
                        if (dp[i - 1][j - p][k - q] != -1 && cur >= 0)
                        {
                            if (dp[i][j][k] > tot * c)
                            {
                                p = j + 1;
                                break;
                            }
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - p][k - q] + cur / p3);
                        }
                    }
    ll ans = 0;
    for (int i = 0; i <= tot * a; i++)
        for (int j = 0; j <= tot * b; j++)
            ans = max(ans, calc(i, j, dp[n][i][j]));
    cout << ans;
    return 0;
}