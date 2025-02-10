#include <bits/stdc++.h>
using namespace std;
int s, dp[10010][10010], ans, a[2010], b[2010];
void read(int x)
{

    int t, k;
    cin >> t >> k;
    t = t << 1;
    if (k > 0)
    {
        for (int i = 1; i <= k; i++)
        {
            cin >> a[i] >> b[i];
        }
        for (int i = 1; i <= k; i++)
        {
            for (int j = s; j >= t + b[i]; j--)
            {
                dp[x][j] = max(dp[x][j - b[i]] + a[i], dp[x][j]);
            }
        }
    }
    if (!k)
    {
        read(x << 1);
        read(x << 1 | 1);
        for (int i = s; i >= t; i--)
            for (int j = 0; j <= i - t; j++)
            {
                dp[x][i] = max(dp[x][i], dp[x << 1][j] + dp[x << 1 | 1][i - j - t]);
            }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    // freopen("steal.in","r",stdin);
    // freopen("steal.out","w",stdout);
    cin >> s;
    s--;
    read(1);
    cout << dp[1][s];
    return 0;
}
