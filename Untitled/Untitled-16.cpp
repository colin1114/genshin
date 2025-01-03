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
    tree[rt].data = tree[rt << 1].data + tree[rt << 1 | 1].data;
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
    tree[rt].data = tree[rt << 1].data + tree[rt << 1 | 1].data;
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
        return query(l, mid, rt << 1) + query(mid + 1, r, rt << 1 | 1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> q;
    build(1, n, 1);
    while (q--)
    {
        ll op, x, y;
        cin >> op >> x >> y;
        if (op == 1)
            modify(x, y, 1), a[x] = y;
        else
        {
            vector<PII> id;
            for (int i = x; i <= y; i++)
                if (a[i] < 0)
                {
                    ll j = i;
                    while (1)
                    {
                        j++;
                        if (j > y || a[j] > 0)
                            break;
                    }
                    id.push_back({i, j - 1});
                }
            // for (auto v : id)
            //     cout << v.x << ' ' << v.y << endl;
            vector<PII> s;
            if (id.size() == 0)
                s.push_back({x, y});
            else if (x == y || (id.size() == 1 && id[0].x == x && id[0].y == y))
                s.push_back({x, y});
            else
            {
                ll i = x, l;
                while (1)
                {
                    if (a[i] > 0)
                    {
                        l = i;
                        break;
                    }
                    i++;
                }
                for (auto v : id)
                {
                    if (l > v.x - 1)
                        continue;
                    s.push_back({l, v.x - 1});
                    l = v.y + 1;
                }
                if (l <= y)
                    s.push_back({l, y});
                if (s.size() == 0)
                    s.push_back({x, y});
            }
            // cerr << "OK 6\n";
            ll ans = -1e18;
            for (auto v : s)
                ans = max(ans, query(v.x, v.y, 1));
            // cerr << "OK 7\n";
            cout << ans << endl;
        }
    }
    return 0;
}