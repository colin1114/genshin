#include <bits/stdc++.h>
#define ll long long

#define endl '\n'

#define PII pair<ll, ll>

#define x first

#define y second

using namespace std;
const int E = 1e6 + 5;
ll n;
ll dis[E], pr[E];
vector<PII> edge[E];
inline void dfs(ll u, ll fa, ll w)
{
    dis[u] = w;
    pr[u] = fa;
    for (auto v : edge[u])
        if (v.x != fa)
            dfs(v.x, u, w + v.y);
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        edge[x].push_back({y, z});
        edge[y].push_back({x, z});
    }
    dfs(0, -1, 0);
    ll max1 = -1, max1id, max2id;
    for (int i = 1; i < n; i++)
        if (dis[i] > max1)
            max1 = dis[i], max1id = i;
    memset(dis, 0, sizeof dis);
    memset(pr, 0, sizeof dis);
    max1 = -1;
    dfs(max1id, -1, 0);
    for (int i = 0; i < n; i++)
        if (dis[i] > max1)
            max1 = dis[i], max2id = i;
    ll x = max2id;
    vector<ll> ans;
    while (x != -1)
    {
        ans.push_back(x);
        x = pr[x];
    }
    cout << max1 << " " << ans.size() << endl;
    for (auto v : ans)
        cout << v << " ";
    return 0;
}