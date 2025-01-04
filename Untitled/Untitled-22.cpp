#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
ll m, n;
ll x[E], y[E];
ll s[E], t[E];
ll a[E], sum[E];
ll dp[60][60][1001];
map<ll, vector<ll>> mp;
set<ll> st;
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
        cin >> s[i];
    ll cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> t[i];
        // ll j = i;
        // cnt++;
        // while (1)
        // {
        //     j++;
        //     if (s[i] != s[j])
        //         break;
        //     mp[cnt].push_back(t[i]);
        // }
        // x[cnt] = s[i];
        // i = j - 1;
    }
    // for (int i = 1; i <= cnt; i++)
    //     cerr << x[i] << ' ';
    // cerr << endl;
    // for (int i = 1; i <= cnt; i++)
    // {
    //     for (auto v : mp[i])
    //         y[i] += v;
    //     cerr << y[i] << ' ';
    // }
    // for (auto v : st)
    // {
    //     for (auto u : mp[v])
    // }
    // m = cnt;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= t[i]; j++)
            a[++cnt] = s[i];
    cerr << cnt << endl;
    for (int i = 1; i <= cnt; i++)
        cerr << a[i] << ' ';
    cerr << endl;
    ll cnt1 = 0;
    for (int i = 1; i <= cnt; i++)
    {
        ll j = i;
        cnt1++;
        while (1)
        {
            j++;
            if (a[i] != a[j])
                break;
        }
        x[cnt1] = a[i];
        y[cnt1] = j - i;
        cerr << i << ' ' << j << endl;
        i = j - 1;
    }
    for (int i = 1; i <= cnt1; i++)
        cerr << y[i] << ' ';
    cerr << endl;
    for (int i = 1; i <= m; i++)
        for (int j = i + 1; j <= m; j++)
            if (x[i] == x[j])
                sum[i] += y[j];
    // for (int i = 1; i <= m; i++)
    //     cout << sum[i] << ' ';
    // cout << endl;
    memset(dp, 0xcf, sizeof dp);
    for (int i = 1; i <= m; i++)
        for (int j = 0; j <= sum[i]; j++)
            dp[i][i][j] = (y[i] + j) * (y[i] + j);
    for (int len = 2; len <= m; len++)
        for (int i = 1; i + len - 1 <= m; i++)
        {
            ll j = i + len - 1;
            for (int k = 0; k <= sum[j]; k++)
                dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][0] + (y[j] + k) * (y[j] + k));
            for (int m = i; m < j; m++)
                if (x[m] == x[j])
                    for (int k = 0; k <= sum[j]; k++)
                        dp[i][j][k] = max(dp[i][j][k], dp[i][m][y[j] + k] + dp[m + 1][j - 1][0]);
        }
    cout << dp[1][m][0] << endl;
    return 0;
}