#include <bits/stdc++.h>
#define endl '\n'

#define ll long long

#define PII pair<ll, ll>

#define x first

#define y second

using namespace std;
const int E = 1e6 + 5;
ll n, m;
ll a[E];
struct node
{
    ll l, r, s, data;
} tree[E << 2];
inline node merge(node u, node v)
{
    node ans;
    ans.s = u.s + v.s;
    ans.l = max(u.l, u.s + v.l);
    ans.r = max(v.r, v.s + u.r);
    ans.data = max(max(u.data, v.data), u.r + v.l);
    return ans;
}
inline void build(ll l, ll r, ll id)
{
    tree[id].l = tree[id].r = tree[id].s = tree[id].data = 0;
    if (l == r)
    {
        tree[id].l = tree[id].r = tree[id].s = tree[id].data = a[l];
        return;
    }
    ll mid = (l + r) >> 1;
    build(l, mid, id << 1);
    build(mid + 1, r, id << 1 | 1);
    tree[id] = merge(tree[id << 1], tree[id << 1 | 1]);
}
inline void modify(ll x, ll l, ll r)
{
    if (l == r)
    {
        tree[x].l = tree[x].r = tree[x].s = tree[x].data = a[l];
        return;
    }
    ll mid = (l + r) >> 1;
    modify(x << 1, l, mid);
    modify(x << 1 | 1, mid + 1, r);
    tree[x] = merge(tree[x << 1], tree[x << 1 | 1]);
}
inline node query(ll x, ll l, ll r, ll u, ll v)
{
    if (u <= l && r <= v)
        return tree[x];
    ll mid = (l + r) >> 1;
    node p, q;
    if (u <= mid)
        p = query(x << 1, l, mid, u, v);
    if (v > mid)
        q = query(x << 1 | 1, mid + 1, r, u, v);
    if (v <= mid)
        return p;
    if (u > mid)
        return q;
    return merge(p, q);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, n, 1);
    cin >> m;
    while (m--)
    {
        ll op, x, y;
        cin >> op >> x >> y;
        if (op == 1)
        {
            a[x] = y;
            modify(1, 1, n);
        }
        else
            cout << query(1, 1, n, x, y).data << endl;
    }
    return 0;
}