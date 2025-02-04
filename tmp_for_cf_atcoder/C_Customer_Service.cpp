#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
struct Edge
{
    ll to, rev;
    ll cap;
};

struct Dinic
{
    ll E;
    vector<vector<Edge>> edge;
    vector<ll> level, it;

    Dinic(ll E) : E(E), edge(E), level(E), it(E) {}

    void add_edge(ll s, ll t, ll cap)
    {
        Edge a = {t, edge[t].size(), cap};
        Edge b = {s, edge[s].size(), 0};
        edge[s].push_back(a);
        edge[t].push_back(b);
    }

    bool bfs(ll s, ll t)
    {
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        queue<ll> q;
        q.push(s);
        while (!q.empty())
        {
            ll u = q.front();
            q.pop();
            for (auto &e : edge[u])
            {
                if (level[e.to] < 0 && e.cap)
                {
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] >= 0;
    }

    ll dfs(ll u, ll t, ll flow)
    {
        if (!flow)
            return 0;
        if (u == t)
            return flow;
        for (; it[u] < edge[u].size(); it[u]++)
        {
            Edge &e = edge[u][it[u]];
            if (level[e.to] == level[u] + 1 && e.cap)
            {
                ll x = dfs(e.to, t, min(flow, e.cap));
                if (x)
                {
                    e.cap -= x;
                    edge[e.to][e.rev].cap += x;
                    return x;
                }
            }
        }
        return 0;
    }

    ll max_flow(ll s, ll t)
    {
        ll flow = 0;
        while (bfs(s, t))
        {
            fill(it.begin(), it.end(), 0);
            while (ll x = dfs(s, t, INT_MAX))
                flow += x;
        }
        return flow;
    }
};
inline void solve()
{
    ll n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    vector<vector<ll>> sum(n, vector<ll>(n + 1, 0));
    vector<ll> tot(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            sum[i][j + 1] = sum[i][j] + a[i][j];
        tot[i] = sum[i][n];
    }
    ll ans = 0;
    for (int m = 1; m <= n; m++)
    {
        ll cnt = m;
        struct cand
        {
            ll i, k, r;
        };
        vector<cand> cands;
        for (int i = 0; i < n; i++)
            for (int k = 1; k <= n; k++)
            {
                ll r = tot[i] - sum[i][k];
                if (r < m)
                    cands.push_back({i, k, r});
            }
        ll S = 0;
        ll A = 1;
        ll B = A + cnt;
        ll C = cands.size();
        Dinic dinic(B + C + C + n + n + 1);
        for (int r = 0; r < cnt; r++)
            dinic.add_edge(S, A + r, 1);
        for (int id = 0; id < C; id++)
        {
            int r = cands[id].r;
            dinic.add_edge(A + r, B + id, 1);
        }
        for (int id = 0; id < C; id++)
            dinic.add_edge(B + id, B + C + id, 1);
        for (int id = 0; id < C; id++)
        {
            ll i = cands[id].i, k = cands[id].k;
            dinic.add_edge(B + C + id, B + C + C + i, 1);
            dinic.add_edge(B + C + id, B + C + C + n + (k - 1), 1);
        }
        for (int i = 0; i < n; i++)
            dinic.add_edge(B + C + C + i, B + C + C + n + n, 1);
        for (int k = 0; k < n; k++)
            dinic.add_edge(B + C + C + n + k, B + C + C + n + n, 1);

        ll f = dinic.max_flow(S, B + C + C + n + n);
        if (f == m)
            ans = m;
    }
    cout << ans << "\n";
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
