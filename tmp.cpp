#include <bits/stdc++.h>
#define ll long long

#define endl '\n'

#define PII pair<ll, ll>

#define x first

#define y second

using namespace std;
const int E = 1e6 + 5;
ll n, len, l, r;
ll s[E];
map<PII, ll> mp;
inline ll count(ll x)
{
    ll ans = 0;
    while (x)
        ans++, s[ans] = x % 10, x /= 10;
    return ans;
}
inline ll dfs(ll i, ll p, bool flag)
{
    if (i == 0)
        return 1;
    if (!flag && mp[{i, p}] != 0)
        return mp[{i, p}];
    ll ans = 0;
    for (int j = 0; j <= (flag ? s[i] : 9); j++)
        if ((p == 4 && j == 9))
            continue;
        else
            ans += dfs(i - 1, j, flag && j == (flag ? s[i] : 9));
    if (!flag)
        mp[{i, p}] = ans;
    return ans;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> r;
        l = 1;
        // cerr << l << ' ' << r << endl;
        mp.clear();
        len = count(r);
        ll x = dfs(len, 0, 1);
        len = count(l - 1);
        ll y = dfs(len, 0, 1);
        // cerr << x << ' ' << y << endl;           
        cout << r - x + y << endl;
    }
    return 0;
}