#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
ll n, m, sum;
ll a[E], s[E];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 2; i <= n; i++)
    {
        ll x = a[i - 1], y;
        if (a[i - 1] > a[i])
            y = a[i] + m;
        else
            y = a[i];
        sum += y - x;
        if (x <= y - 2)
            x += 2, s[x]++, s[y + 1] -= y - x + 2, s[y + 2] += y - x + 1;
    }
    for (int i = 2; i <= 1e6; i++)
        s[i] += s[i - 1];
    for (int i = 2; i <= 1e6; i++)
        s[i] += s[i - 1];
    ll ans = 1e18;
    for (int i = 1; i <= m; i++)
        ans = min(ans, sum - s[i] - s[i + m]);
    cout << ans;
    return 0;
}