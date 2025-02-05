#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
ll n, len;
string s;
map<PII, ll> mp;
inline ll count(ll x)
{
    ll ans = 0;
    while (x)
        ans++, x /= 10;
    return ans;
}
inline ll dfs(ll i, ll p, bool flag) // You can add something there...
{
    if (i == len)
        return p;
    if (!flag && mp[{i, p}] != 0)
        return mp[{i, p}];
    ll ans = 0;
    for (int j = 0; j <= (flag ? s[i] - '0' : 9); j++)
        // ans += dfs(i + 1, p + (1 == j), flag && (j == (flag ? s[i] - '0' : 9)));
        ans += dfs(i + 1, ...., ....); // 在这里写状态转移。
    if (!flag)
        mp[{i, p}] = ans;
    return ans;
}
int main()
{
    cin >> n;
    s = to_string(n);
    len = count(n);
    cout << dfs(0, 0, 1);
    return 0;
}