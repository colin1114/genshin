
#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;
const int E = 1e6 + 5;
ll n, q;
ll a[E];
struct node
{
    ll val;
} tree[E << 2];
inline void update(ll rt)
{
    tree[rt].val = __gcd(tree[rt * 2].val, tree[rt * 2 + 1].val);
}
inline void build(ll rt, ll l, ll r)
{
    if (l == r)
    {
        tree[rt].val = a[l];
        return;
    }
    ll mid = l + r >> 1;
    build(rt * 2, l, mid);
    build(rt * 2 + 1, mid + 1, r);
    update(rt);
}
inline void update(ll rt, ll l, ll r, ll pos, ll val)
{
    if (l == r)
    {
        tree[rt].val = val;
        return;
    }
    ll mid = l + r >> 1;
    if (pos <= mid)
        update(rt * 2, l, mid, pos, val);
    else
        update(rt * 2 + 1, mid + 1, r, pos, val);
    update(rt);
}
inline ll query(ll rt, ll l, ll r, ll cl, ll cr, ll x)
{
    if (r < cl || l > cr)
        return 0;
    if (tree[rt].val % x == 0)
        return 0;
    if (l == r)
        return 1;
    ll mid = l + r >> 1;
    ll p = query(rt * 2, l, mid, cl, cr, x);
    if (p > 1)
        return 2;
    ll q = query(rt * 2 + 1, mid + 1, r, cl, cr, x);
    ll sum = p + q;
    return (sum > 1) ? 2 : sum;
}
int main()
{
    freopen("math.in", "r", stdin);
    freopen("math.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    ll q;
    cin >> q;
    while (q--)
    {
        ll op, l, r, x;
        cin >> op;
        if (op == 1)
        {
            cin >> l >> r >> x;
            ll v = query(1, 1, n, l, r, x);
            if (v <= 1)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
        {
            cin >> l >> x;
            update(1, 1, n, l, x);
        }
    }
    return 0;
}