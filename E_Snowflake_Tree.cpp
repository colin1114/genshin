#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
ll n;
vector<ll> edge[E];
ll dis[E];
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        ll u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        dis[i] = edge[i].size();
    ll ans = 0;
    for (int u = 1; u <= n; u++)
    {
        ll x = dis[u];
        if (x == 0)
            continue;
        vector<ll> a;
        for (auto v : edge[u])
            a.push_back(dis[v]);
        sort(a.begin(), a.end(), greater<ll>());
        for (int x = 1; x <= a.size(); x++)
        {
            if (a[x - 1] >= 2)
                ans = max(ans, 1 + x * a[x - 1]);
            else
                break;
        }
    }
    cout << n - ans << endl;
    return 0;
}
