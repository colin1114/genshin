#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
const int Base = 31;
ll n, q;
ll dp[101][E];
inline void init()
{
    for (int i = 2, x; i <= n; i++)
        cin >> x, dp[0][i] = x;
    for (int i = 1; i < 18; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
}
int main()
{
    cin >> n >> q;
    init();
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        for (int i = 0; i < 18; i++)
            if ((y >> i) & 1)
                x = dp[i][x];
        cout << (x == 0 ? -1 : x) << endl;
    }
    return 0;
}