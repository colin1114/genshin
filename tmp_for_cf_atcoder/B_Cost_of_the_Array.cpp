#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;

vector<ll> calc(const vector<ll> &a, ll n)
{
    vector<ll> F(n + 2, 0);
    for (int i = n; i >= 1; i--)
    {
        if (a[i] == 1)
        {
            ll l = 1;
            while (i + l <= n && a[i + l] == l + 1)
                l++;
            F[i] = l;
        }
        else
            F[i] = 0;
    }
    return F;
}
inline ll calc1(const vector<ll> &a, ll n, ll x, ll l, ll m)
{
    ll mask = 0;
    for (int j = 1; j <= m - 1; j++)
    {
        ll pos = x + 2 * j;
        if (pos > n)
            return j;
        if (a[pos] == l + j)
            mask |= (1 << (j - 1));
        else
            return j;
    }
    return m;
}
ll t, n, k;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        ll m = k / 2;
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        ll ans = 1e18;
        vector<ll> F = calc(a, n);
        for (int p = 1; p <= n - k + 1; p++)
        {
            ll max1 = n - p - 2 * (m - 1);
            if (max1 < 1)
                continue;
            ll x = (p + 1 <= n ? F[p + 1] : 0);
            for (int l = 1; l <= max1; l++)
            {
                ll s;
                if (l > x)
                    s = x + 1;
                else
                    s = l + calc1(a, n, p + l, l, m);
                ans = min(ans, s);
                if (ans == 1)
                    break;
                if (l >= ans)
                    break;
            }
            if (ans == 1)
                break;
        }
        cout << ans << "\n";
    }
    return 0;
}
