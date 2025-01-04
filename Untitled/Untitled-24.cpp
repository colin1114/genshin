#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
const int mod = 1e8 + 7;
ll n;
PII a[E];
ll dp[E][50];
ll dp1[1001][1001];
inline bool check(ll x, ll y, ll z)
{
    if ((a[z].x - a[y].x) * (a[y].x - a[x].x) < 0)
        return 0;
    if ((a[z].y - a[y].y) * (a[y].y - a[x].y) < 0)
        return 0;
    return (a[x].x - a[y].x) * (a[z].y - a[y].y) == (a[z].x - a[y].x) * (a[x].y - a[y].y);
}
inline bool check1(ll x, ll y, ll u)
{
    if ((1 << y) & u)
        return 0;
    return (u | dp1[x][y]) == u;
}
inline ll count(ll x)
{
    ll ans = 0;
    while (x)
    {
        if (x & 1)
            ans++;
        x >>= 1;
    }
    return ans;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
            {
                if (i == j || j == k || i == k)
                    continue;
                if (check(i, k, j))
                    dp1[i][j] |= 1 << k;
            }
    for (int i = 0; i < n; i++)
        dp[1 << i][i] = 1;
    ll ans = 0;
    for (int i = 0; i < 1 << n; i++)
        for (int j = 0; j < n; j++)
        {
            if (!dp[i][j])
                continue;
            if (count(i) >= 4)
                ans += dp[i][j], ans %= mod;
            for (int k = 0; k < n; k++)
                if (check1(j, k, i))
                    dp[i | (1 << k)][k] += dp[i][j], dp[i | (1 << k)][k] %= mod;
        }
    cout << ans;
    return 0;
}