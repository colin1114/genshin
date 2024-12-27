#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e7 + 5;
ll n, m;
struct node
{
    ll l, r, a, b;
} a[E];
ll sum[E];
ll s[E];
int main()
{
    // freopen("hack.in", "r", stdin);
    // freopen("hack.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i].l >> a[i].r >> a[i].a >> a[i].b;
    for (int i = 1; i <= m; i++)
    {
        ll x = (a[i].b - a[i].a) / (a[i].r - a[i].l);
        s[a[i].l] += a[i].a;
        s[a[i].l + 1] += x - a[i].a;
        s[a[i].r + 1] -= x + a[i].b;
        s[a[i].r + 2] += a[i].b;
    }
    // ll k = 0;
    // for (int i = 1; i <= n; i++)
    //     k += s[i], sum[i] = k;
    for (int i = 1; i <= n; i++)
        s[i] += s[i - 1];
    for (int i = 1; i <= n; i++)
        s[i] += s[i - 1];
    ll ans = 0, max1 = 0;
    for (int i = 1; i <= n; i++)
        ans ^= s[i], max1 = max(max1, s[i]);
    cout << ans << ' ' << max1;
    return 0;
}