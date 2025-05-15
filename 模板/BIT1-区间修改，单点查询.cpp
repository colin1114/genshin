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
inline ll query(ll l)
{
    ll res = 0;
    for (int i = l; i; i -= i & -i)
        res += bit[i];
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
        add(i + 1, -x);
    }
    while (q--)
    {
        ll op, l, r, x;
        cin >> op;
        if (op == 1)
        {
            cin >> l >> r >> x;
            add(l, x);
            add(r + 1, -x);
        }
        else
        {
            cin >> l;
            cout << query(l) << endl;
        }
    }
    return 0;
}
