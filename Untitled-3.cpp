#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
ll n, ans;
ll a[E], dep[E], in[E], out[E];
vector<ll> edge[E];
inline void init(ll u, ll fa)
{
    dep[u] = dep[fa] + 1;
    for (auto v : edge[u])
        if (v != fa)
            init(v, u);
}
inline void dfs(ll u, ll fa, ll tim, ll stp, ll life)
{
    // cerr << "id: " << u << ", pre: " << fa << ", time: " << tim << ", dep: " << dep[u] << ", step: " << stp << ", life: " << life << ", will " << (a[u] > 0 ? '-' : '+') << ' ' << 1 << " life" << endl;
    if (dep[u] <= tim)
    {
        // cerr << "ok stp = " << stp << endl;
        // cerr << "exit signel: 1\n";
        // cerr << endl;
        ans = max(ans, stp);
        return;
    }
    life += a[u];
    if (life <= 0)
    {
        ans = max(ans, stp);
        // cerr << "ok stp = " << stp << endl;
        // cerr << "exit signel: 2\n";
        return;
    }
    for (auto v : edge[u])
        dfs(v, u, tim + 1, stp + 1, life);
}
int main()
{
    freopen("vol.in", "r", stdin);
    freopen("vol.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        ll u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        in[u]++;
        out[v]++;
        edge[v].push_back(u);
    }
    ll cnt = 0, cnt1 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 1)
            cnt++;
        if (out[i] == 1)
            cnt1++;
    }
    init(1, 0);
    for (int i = 1; i <= n; i++)
        cerr << --dep[i] << ' ';
    if (cnt == n - 2 && cnt1 == n - 2)
    {
        
    }
    for (int i = 1; i <= n; i++)
    {
        // cerr << i << endl;
        ans = 0;
        dfs(i, 0, 0, 0, 1);
        cout << ans << endl;
    }
    return 0;
}