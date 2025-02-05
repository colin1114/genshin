// 另一种写法，将 l, r 内置在 node 中。
// update on 2025-2-5.

#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
ll n;
ll a[E];
struct node
{
    ll l, r, d, lazy;
} ns[E << 2];
inline void update(ll rt)
{
    ns[rt].d = ns[rt << 1].d + ns[rt << 1 | 1].d;
}
inline void push_down(ll rt)
{
    if (ns[rt].lazy == 0)
        return;
    ns[rt << 1].lazy += ns[rt].lazy;
    ns[rt << 1].d += ns[rt].lazy * (ns[rt << 1].r - ns[rt << 1].l + 1);
    ns[rt << 1 | 1].lazy += ns[rt].lazy;
    ns[rt << 1 | 1].d += ns[rt].lazy * (ns[rt << 1 | 1].r - ns[rt << 1 | 1].l + 1);
    ns[rt].lazy = 0;
}
inline void build(ll rt, ll l, ll r)
{
    ns[rt].l = l;
    ns[rt].r = r;
    if (l == r)
    {
        ns[rt].d = a[l];
        return;
    }
    ll mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    update(rt);
}
inline void modify(ll rt, ll l, ll r, ll v)
{
    push_down(rt);
    if (ns[rt].l == l && ns[rt].r == r)
    {
        ns[rt].lazy += v;
        ns[rt].d += v * (ns[rt].r - ns[rt].l + 1);
        return;
    }
    if (ns[rt << 1].r >= r)
        modify(rt << 1, l, r, v);
    else if (ns[rt << 1 | 1].l <= l)
        modify(rt << 1 | 1, l, r, v);
    else
        modify(rt << 1, l, ns[rt << 1].r, v), modify(rt << 1 | 1, ns[rt << 1 | 1].l, r, v);
    update(rt);
}
inline ll query(ll rt, ll l, ll r)
{
    if (ns[rt].l == l && ns[rt].r == r)
        return ns[rt].d;
    push_down(rt);
    ll mid = ns[rt].l + ns[rt].r >> 1;
    if (ns[rt << 1].r >= r)
        return query(rt << 1, l, r);
    else if (ns[rt << 1 | 1].l <= l)
        return query(rt << 1 | 1, l, r);
    else
        return query(rt << 1, l, mid) + query(rt << 1 | 1, mid + 1, r);
}
int main()
{
    ll n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    while (m--)
    {
        ll op, l, r, v;
        cin >> op >> l >> r;
        if (op == 1)
        {
            cin >> v;
            modify(1, l, r, v);
        }
        else
            cout << query(1, l, r) << endl;
    }
    return 0;
}