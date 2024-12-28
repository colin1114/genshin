#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
ll n, m;
ll arr[E], arr1[E];
void push_down(ll rt);
struct node
{
    ll d, l, r;
    ll lazy;
} ns[4 * E];
void update(ll rt)
{
    ns[rt].d = max(ns[rt * 2].d, ns[rt * 2 + 1].d);
}
void build(ll rt, ll l, ll r)
{
    ns[rt].l = l;
    ns[rt].r = r;
    ns[rt].lazy = -1;
    if (l == r)
    {
        ns[rt].d = arr[l];

        return;
    }
    ll mid = (l + r) / 2;
    build(rt * 2, l, mid);
    build(rt * 2 + 1, mid + 1, r);
    update(rt);
}
void push_down(ll rt)
{
    if (ns[rt].lazy < 0)
    {
        return;
    }
    ns[rt << 1].lazy = ns[rt].lazy;
    ns[rt << 1 | 1].lazy = ns[rt].lazy;
    ns[rt << 1].d = ns[rt].lazy;
    ns[rt << 1 | 1].d = ns[rt].lazy;

    ns[rt].lazy = -1;
    update(rt);
}
ll query(ll rt, ll l, ll r)
{
    if (ns[rt].l == l && ns[rt].r == r)
    {
        return ns[rt].d;
    }
    ll mid = (ns[rt].l + ns[rt].r) / 2;
    push_down(rt);

    if (ns[rt * 2].r >= r)
    {
        return query(rt * 2, l, r);
    }
    else if (ns[rt * 2 + 1].l <= l)
    {
        return query(rt * 2 + 1, l, r);
    }
    else
    {
        return max(query(rt * 2, l, mid), query(rt * 2 + 1, mid + 1, r));
    }
}
void update1(ll rt)
{
    ns[rt].d = min(ns[rt * 2].d, ns[rt * 2 + 1].d);
}
void build1(ll rt, ll l, ll r)
{
    ns[rt].l = l;
    ns[rt].r = r;
    ns[rt].lazy = -1;
    if (l == r)
    {
        ns[rt].d = arr[l];

        return;
    }
    ll mid = (l + r) / 2;
    build1(rt * 2, l, mid);
    build1(rt * 2 + 1, mid + 1, r);
    update1(rt);
}
void push_down1(ll rt)
{
    if (ns[rt].lazy < 0)
    {
        return;
    }
    ns[rt << 1].lazy = ns[rt].lazy;
    ns[rt << 1 | 1].lazy = ns[rt].lazy;
    ns[rt << 1].d = ns[rt].lazy;
    ns[rt << 1 | 1].d = ns[rt].lazy;

    ns[rt].lazy = -1;
    update1(rt);
}
ll query1(ll rt, ll l, ll r)
{
    if (ns[rt].l == l && ns[rt].r == r)
    {
        return ns[rt].d;
    }
    ll mid = (ns[rt].l + ns[rt].r) / 2;
    push_down1(rt);

    if (ns[rt * 2].r >= r)
    {
        return query1(rt * 2, l, r);
    }
    else if (ns[rt * 2 + 1].l <= l)
    {
        return query1(rt * 2 + 1, l, r);
    }
    else
    {
        return min(query1(rt * 2, l, mid), query1(rt * 2 + 1, mid + 1, r));
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr1[i] = arr[i];
    }
    build1(1, 1, n);
    for (int i = 1; i <= n - m + 1; i++)
    {
        ll b, c;
        cin >> b >> c;
        cout << query1(1, i, i + m - 1) << " ";
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        arr[i] = arr1[i];
    }
    build(1, 1, n);
    for (int i = 1; i <= n - m + 1; i++)
    {
        ll b, c;
        cin >> b >> c;
        cout << query(1, i, i + m - 1) << " ";
    }
    return 0;
}