#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
string a;
ll pre[E], bs[E], len;
inline void init()
{
    bs[0] = 1;
    for (int i = 1; i <= len; i++)
        pre[i] = pre[i - 1] * 131 + a[i - 1], bs[i] = bs[i - 1] * 131;
}
inline bool check(ll x)
{
    ll tmp = pre[x] - pre[0] * bs[x];
    for (int i = x + 1; i <= len; i += x)
    {
        ll r = i + x - 1;
        if (pre[r] - pre[i - 1] * bs[r - i + 1] != tmp)
            return 0;
    }
    return 1;
}
int main()
{
    while (cin >> a && a != ".")
    {
        len = a.length();
        init();
        vector<ll> vct;
        for (int i = 1; i * i <= len; i++)
        {
            if (len % i == 0)
            {
                vct.push_back(i);
                if (len / i != i)
                    vct.push_back(len / i);
            }
        }
        sort(vct.begin(), vct.end());
        for (auto x : vct)
        {
            if (check(x))
            {
                cout << len / x << endl;
                break;
            }
        }
    }
    return 0;
}