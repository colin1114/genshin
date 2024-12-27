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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i].l >> a[i].r >> a[i].a >> a[i].b;
    for (int i = 1; i <= m; i++)
    {
        ll x = (a[i].b - a[i].a) / (a[i].r - a[i].l);
        s[a[i].r] += a[i].a;
        s[a[i].l + 1] -= x - a[i].a;
    }
    return 0;
}