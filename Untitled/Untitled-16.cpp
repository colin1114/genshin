#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
ll n, q;
ll a[E];
struct node
{
    ll l, r, data;
} tree[E << 2];
inline void build(ll l, ll r, ll rt)
{
    tree[rt].l = l;
    tree[rt].r = r;
    if (tree[rt].l == tree[rt].r)
    {
        tree[rt].data = a[l];
        return;
    }
    ll mid = l + r >> 1;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
    tree[rt].data = max(tree[rt << 1].data, tree[rt << 1 | 1].data);
}
inline void modify(ll x, ll dat, ll rt)
{
    ll mid = tree[rt].l + tree[rt].r >> 1;
    if (tree[rt].l == tree[rt].r && tree[rt].l == x)
    {
        tree[rt].data = dat;
        return;
    }
    if (x <= mid)
        modify(x, dat, rt << 1);
    else
        modify(x, dat, rt << 1 | 1);
    tree[rt].data = max(tree[rt << 1].data, tree[rt << 1 | 1].data);
}
inline ll query(ll l, ll r, ll rt)
{
    ll mid = tree[rt].l + tree[rt].r >> 1;
    if (tree[rt].l == l && tree[rt].r == r)
        return tree[rt].data;
    if (r <= mid)
        return query(l, r, rt << 1);
    else if (mid + 1 <= l)
        return query(l, r, rt << 1 | 1);
    else
        return max(query(l, mid, rt << 1), query(mid + 1, r, rt << 1 | 1));
}
int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, n, 1);
    while (q--)
    {
        ll op, x, y;
        cin >> op >> x >> y;
        if (op == 1)
            modify(x, y, 1);
        else
            cout << query(x, y, 1) << endl;
    }
    return 0;
}