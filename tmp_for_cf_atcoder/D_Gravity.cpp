#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
ll n, w;
int main()
{
    cin >> n >> w;
    vector<vector<PII>> edge(w + 1);
    vector<ll> p(n + 1), q(n + 1);
    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        p[i] = x;
        q[i] = y;
        edge[x].push_back({y, i});
    }
    for (int x = 1; x <= w; x++)
        sort(edge[x].begin(), edge[x].end(), [](auto &a, auto &b)
             { return a.first < b.first; });
    vector<ll> order(n + 1, 0);
    bool flag = 1;
    ll min1 = 1e18;
    for (int x = 1; x <= w; x++)
    {
        if (edge[x].empty())
        {
            flag = 0;
            break;
        }
        else
        {
            min1 = min(min1, (ll)edge[x].size());
            for (int i = 0; i < edge[x].size(); i++)
            {
                ll bid = edge[x][i].y;
                order[bid] = i + 1;
            }
        }
    }
    vector<ll> m;
    if (flag)
    {
        m.resize(min1);
        for (int r = 1; r <= min1; r++)
        {
            ll mx = 0;
            for (int x = 1; x <= w; x++)
                if (edge[x].size() >= r)
                    mx = max(mx, (ll)edge[x][r - 1].x);
            m[r - 1] = mx;
        }
    }
    ll Q;
    cin >> Q;
    while (Q--)
    {
        ll t, a;
        cin >> t >> a;
        if (!flag)
        {
            cout << "Yes\n";
            continue;
        }
        ll rnk = order[a];
        ll R = upper_bound(m.begin(), m.end(), t) - m.begin();
        cout << (rnk <= R ? "No" : "Yes") << "\n";
    }
    return 0;
}