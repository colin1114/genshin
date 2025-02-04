#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
ll n;
ll a[E];
inline bool check(ll x)
{
    for (int i = 0; i < x; i++)
        if (a[i] * 2 > a[n - x + i])
            return 0;
    return 1;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll l = 0, r = n / 2, ans = 0;
    while (l <= r)
    {
        ll mid = l + r >> 1;
        if (check(mid))
            l = mid + 1, ans = mid;
        else
            r = mid - 1;
    }
    cout << ans << endl;
    return 0;
}