#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
const ll INF = 1e18;
ll n, m, x, y;
struct node
{
    ll x, y, id;
} a[E], b[E];
bool vis[E];
inline bool cmp_y(const node &a, const node &b)
{
    if (a.y != b.y)
        return a.y < b.y;
    return a.x < b.x;
}
inline bool cmp_x(const node &a, const node &b)
{
    if (a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}
int main()
{
    cin >> n >> m >> x >> y;
    for (int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y, a[i].id = i, b[i] = a[i];
    sort(a, a + n, cmp_y);
    sort(b, b + n, cmp_x);
    vector<pair<char, ll>> s(m);
    for (int i = 0; i < m; i++)
        cin >> s[i].x >> s[i].y;
    ll cnt = 0;
    for (int i = 0; i < m; i++)
    {
        char op = s[i].x;
        ll c = s[i].y;
        ll x1 = x;
        ll y1 = y;
        if (op == 'U')
            y1 += c;
        else if (op == 'D')
            y1 -= c;
        else if (op == 'L')
            x1 -= c;
        else if (op == 'R')
            x1 += c;
        else
            continue;
        if (op == 'U' || op == 'D')
        {
            ll x0 = x;
            ll min_y = min(y, y1);
            ll max_y = max(y, y1);
            node u = {x0, min_y, -1};
            node v = {x0, max_y, INF};
            auto l = lower_bound(b, b + n, u, cmp_x);
            auto r = upper_bound(b, b + n, v, cmp_x);
            for (auto j = l; j != r; j++)
                if (!vis[j->id])
                    vis[j->id] = 1, cnt++;
        }
        else
        {
            int y0 = y;
            ll min_x = min(x, x1);
            ll max_x = max(x, x1);
            node u = {min_x, y0, -1};
            node v = {max_x, y0, INF};
            auto l = lower_bound(a, a + n, u, cmp_y);
            auto r = upper_bound(a, a + n, v, cmp_y);
            for (auto j = l; j != r; j++)
                if (!vis[j->id])
                    vis[j->id] = 1, cnt++;
        }
        x = x1;
        y = y1;
    }
    cout << x << " " << y << " " << cnt;
    return 0;
}
