#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
ll t, a, b;
bitset<E> dp[11];
int main()
{
    cin >> t >> a >> b;
    dp[0][0] = 1;
    dp[1][0] = 1;
    for (int j = 0; j <= t; j++)
    {
        if (!dp[0][j])
            continue;
        if (j + a <= t)
            dp[0][j + a] = 1;
        if (j + b <= t)
            dp[0][j + b] = 1;
        dp[1][j / 2] = 1;
    }
    for (int j = 0; j <= t; j++)
    {
        if (!dp[1][j])
            continue;
        if (j + a <= t)
            dp[1][j + a] = 1;
        if (j + b <= t)
            dp[1][j + b] = 1;
        dp[1][j / 2] = 1;
    }
    ll ans = t;
    for (;;)
        if (!dp[1][ans])
            ans--;
        else
            break;
    cout << ans << endl;
    return 0;
}