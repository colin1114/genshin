// SGT 区间修改区间查询模板
// update on 2025-1-22.
// lazy = min.
// lazy1 = max.

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
struct node
{
    ll d, lazy, lazy1;
} ns[E * 8];
ll n, m;

// inline void update(ll rt)
// {
//     ns[rt].d = ns[rt * 2].d + ns[rt * 2 + 1].d;
// }
// inline void build(ll rt, ll cl, ll cr)
// {
//     ns[rt].d = 0, ns[rt].lazy = 0;
//     if (cl == cr)
//     {
//         // ns[rt].d = ns[cl];
//         return;
//     }
//     ll mid = (cl + cr) >> 1;
//     build(rt * 2, cl, mid);
//     build(rt * 2 + 1, mid + 1, cr);
//     update(rt);
// }

inline void fx(ll rt, ll k)
{
    ns[rt].lazy = max(ns[rt].lazy, k);
    ns[rt].lazy1 = max(ns[rt].lazy1, k);
}

inline void fy(ll rt, ll k)
{
    ns[rt].lazy = min(ns[rt].lazy, k);
    ns[rt].lazy1 = min(ns[rt].lazy1, k);
}

inline void push_down(ll rt, ll l, ll r) // min:lazy
{                                        // max:lazy1
    fx(rt * 2, ns[rt].lazy1);
    fx(rt * 2 + 1, ns[rt].lazy1);
    fy(rt * 2, ns[rt].lazy);
    fy(rt * 2 + 1, ns[rt].lazy);
    ns[rt].lazy1 = 0;
    ns[rt].lazy = 1e18;
}

inline void query(ll rt, ll l, ll r)
{

    if (l == r)
    {
        cout << ns[rt].lazy1 << endl;
        return;
    }
    push_down(rt, l, r);
    ll mid = (l + r) >> 1;
    query(rt * 2, l, mid);
    query(rt * 2 + 1, mid + 1, r);
}

inline void modily(ll rt, ll v, ll l, ll r, ll cl, ll cr, bool tags)
{
    // cerr << cl << ' ' << cr << endl;
    if (l <= cl && cr <= r)
    {
        if (tags == 0)
            fx(rt, v);
        else
            fy(rt, v);
        return;
    }
    push_down(rt, cl, cr);
    ll mid = (cl + cr) >> 1;
    if (l <= mid)
        modily(rt * 2, v, l, r, cl, mid, tags);
    if (r > mid)
        modily(rt * 2 + 1, v, l, r, mid + 1, cr, tags);
}
int main()
{
    cin >> n >> m;
    // build(1, 1, n);
    for (int i = 0; i <= 1e6; i++)
        ns[i].lazy = 1e18;
    for (int i = 1; i <= m; i++)
    {
        ll op, l, r, h;
        cin >> op >> l >> r >> h;
        if (op == 1)
            modily(1, h, l, r, 0, n - 1, 0);
        else if (op == 2)
            modily(1, h, l, r, 0, n - 1, 1);
    }
    query(1, 0, n - 1);
    return 0;
}