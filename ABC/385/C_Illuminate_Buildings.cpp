#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
ll n;
ll a[E];
ll dp[3005][3005];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    unordered_map<ll, vector<ll>> mp;
    for (int i = 0; i < n; ++i)
        mp[a[i]].push_back(i);
    ll ans = 1;
    for (auto &[a, L] : mp)
    {
        ll len = L.size();
        if (len <= ans)
            continue;
        for (int j = 0; j < len; ++j)
        {
            for (int i = 0; i < j; ++i)
            {
                int d = L[j] - L[i];
                if (d <= 0)
                    continue;
                if (d > n)
                    continue;
                if (dp[i][d] > 0)
                    dp[j][d] = dp[i][d] + 1;
                else
                    dp[j][d] = 2;
                if (dp[j][d] > ans)
                    ans = dp[j][d];
            }
        }
    }
    cout << ans;
    return 0;
}
