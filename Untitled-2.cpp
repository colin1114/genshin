#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
ll n, sum;
ll a[E];
int main()
{
    freopen("sub.in", "r", stdin);
    freopen("sub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], sum += a[i];
    ll avg = sum / n;
    ll md = sum % n;
    sort(a + 1, a + n + 1);
    ll ans = 0;
    for (int i = 1; i <= n - md; i++)
        ans += max(0ll, a[i] - avg);
    for (int i = n - md + 1; i <= n; i++)
        ans += max(0ll, a[i] - avg - 1);
    cout << ans << endl;
    return 0;
}