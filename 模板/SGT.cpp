// SGT 区间修改区间查询模板（l, r 外置）
// update on 2025-1-22.

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
struct node
{
    ll d, lazy;
} ns[E * 4];
ll n, m;
inline void update(ll rt)
{
    ns[rt].d = ns[rt * 2].d + ns[rt * 2 + 1].d;
}
inline void build(ll rt, ll cl, ll cr)
{
    ns[rt].d = 0, ns[rt].lazy = 0;
    if (cl == cr)
    {
        // ns[rt].d = ns[cl];
        return;
    }
    ll mid = (cl + cr) >> 1;
    build(rt * 2, cl, mid);
    build(rt * 2 + 1, mid + 1, cr);
    update(rt);
}
inline void push_down(ll rt, ll l, ll r)
{
    ll mid = l + r >> 1;
    ns[rt * 2].d += ns[rt].lazy * (mid - l + 1);
    ns[rt * 2].lazy += ns[rt].lazy;
    ns[rt * 2 + 1].d += ns[rt].lazy * (r - mid);
    ns[rt * 2 + 1].lazy += ns[rt].lazy;
    ns[rt].lazy = 0;
}

inline ll query(ll rt, ll l, ll r, ll cl, ll cr)
{
    if (cl >= l && cr <= r)
        return ns[rt].d;
    ll res = 0;
    push_down(rt, cl, cr);
    ll mid = (cl + cr) >> 1;
    if (l <= mid)
        res += query(rt * 2, l, r, cl, mid);
    if (r > mid)
        res += query(rt * 2 + 1, l, r, mid + 1, cr);
    return res;
}

inline void modily(ll rt, ll v, ll l, ll r, ll cl, ll cr)
{
    if (cl >= l && cr <= r)
    {
        ns[rt].lazy += v;
        ns[rt].d += v * (cr - cl + 1);
        return;
    }
    push_down(rt, cl, cr);
    ll mid = (cl + cr) >> 1;
    if (l <= mid)
        modily(rt * 2, v, l, r, cl, mid);
    if (r > mid)
        modily(rt * 2 + 1, v, l, r, mid + 1, cr);
    ns[rt].d = (ns[rt * 2].d + ns[rt * 2 + 1].d);
}

int main()
{
    cin >> n >> m;
    build(1, 1, n); // 建树 1 ~ n
    for (int i = 1; i <= m; i++)
    {
        ll op;
        cin >> op;
        if (op == 1)
        {
            ll l, r, v;
            cin >> l >> r >> v;
            modily(1, v, l, r, 1, n); // 区间修改 l ~ r 加上 v
        }
        else
        {
            ll l, r;
            cin >> l >> r;
            cout << query(1, l, r, 1, n) << '\n'; // 区间查询 l ~ r
        }
    }
    return 0;
}