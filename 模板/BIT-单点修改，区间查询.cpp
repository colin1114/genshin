#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
ll n, q;
ll bit[E];
inline void add(ll x, ll k)
{
    for (int i = x; i <= n; i += i & -i)
        bit[i] += k;
}
inline ll query(ll l, ll r)
{
    ll res = 0;
    for (int i = r; i; i -= i & -i)
        res += bit[i];
    for (int i = l - 1; i; i -= i & -i)
        res -= bit[i];
    return res;
}

int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        add(i, x);
    }
    while (q--)
    {
        ll op, x, y;
        cin >> op >> x >> y;
        if (op == 1)
            add(x, y);
        else
            cout << query(x, y) << endl;
    }
    return 0;
}
