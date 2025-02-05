#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
ll n, m, cnt, ans;
ll dfn[E], low[E], sum[E];
vector<ll> edge[E];
inline void tarjan(ll u, ll fa)
{
    low[u] = dfn[u] = ++cnt;
    for (auto v : edge[u])
    {
        if (!dfn[v])
        {
            tarjan(v, u);
            low[u] = min(low[v], low[u]);
            if (low[v] >= dfn[u])
                sum[u]++;
        }
        else if (v != fa)
            low[u] = min(dfn[v], low[u]);
    }
}
int main()
{
    while (cin >> n >> m && !(n == 0 && m == 0))
    {
        cnt = 0;
        ll tot = 0;
        for (int i = 0; i <= n; i++)
            edge[i].clear();
        memset(dfn, 0, sizeof dfn);
        memset(low, 0, sizeof low);
        memset(sum, 0, sizeof sum);
        for (int i = 1; i <= m; i++)
        {
            ll x, y;
            cin >> x >> y;
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        ans = -1e18;
        ll cnt1 = 0;
        for (int i = 0; i < n; i++)
            if (!dfn[i])
            {
                cnt1++;
                tarjan(i, -1);
                sum[i]--;
            }
        for (int i = 0; i < n; i++)
            ans = max(ans, sum[i]);
        cout << ans + cnt1 << endl;
    }
    return 0;
}