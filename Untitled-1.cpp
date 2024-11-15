#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
string a, b;
int main()
{
    cin >> a >> b;
    ll len = b.length();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    ll cnt = 0;
    map<ll, bool> mp;
    ll cnt1 = -1;
    while (1)
    {
        cnt1++;
        ll x = a.find(b);
        if (x == string::npos)
            break;
        cout << x << ' ' << cnt1 << ' ' << a << endl;
        if (mp[x + cnt1])
        {
            a.pop_back();
            continue;
        }
        mp[x + cnt1] = 1;
        a.pop_back();
        cnt++;
    }
    cout << cnt;
    return 0;
}