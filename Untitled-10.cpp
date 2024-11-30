#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
ll n, k;
ll a[E];
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    unordered_map<ll, ll> mp;
    ll sum = 0, ans = 0;
    mp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
        if (mp[sum - k] != 0)
            ans += mp[sum - k];
        mp[sum]++;
    }
    cout << ans;
    return 0;
}