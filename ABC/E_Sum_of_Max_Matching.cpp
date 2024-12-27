#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
ll n, m, k;
struct node
{
    ll x, y, z;
} a[E];
ll fa[E], cnt[E];
ll ans = 0;
inline ll find(ll x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
inline bool cmp(node x, node y)
{
    if (x.x == y.x)
    {
        if (x.y == y.y)
            return x.z < y.z;
        return x.y < y.y;
    }
    return x.x < y.x;
}
inline void unite(ll x, ll y, ll z)
{
    ll p = find(y), q = find(z);
    if (p == q)
        return;
    if (cnt[p] < cnt[q])
        swap(p, q);
    if (cnt[p] > 0 && cnt[q] < 0)
        ans += min(cnt[p], -cnt[q]) * x;
    fa[q] = p;
    cnt[p] += cnt[q];
}
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= 1e6; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        a[i] = {z, x, y};
    }
    sort(a + 1, a + 1 + m, cmp);
    for (int i = 1; i <= k; i++)
    {
        ll x;
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i <= k; i++)
    {
        ll x;
        cin >> x;
        cnt[x]--;
    }
    for (int i = 1; i <= m; i++)
        unite(a[i].x, a[i].y, a[i].z);
    cout << ans;
    return 0;
}