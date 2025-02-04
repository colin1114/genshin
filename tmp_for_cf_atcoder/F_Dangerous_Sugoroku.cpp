#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
ll n, m, a, b;
struct node
{
    ll x, y;
    node(ll s, ll e) : x(s), y(e) {}
};
inline bool check(const node &a, const node &b)
{
    return a.x <= b.y && b.x <= a.y;
}
inline node merge(const node &a, const node &b)
{
    return node(min(a.x, b.x), max(a.y, b.y));
}
int main()
{
    cin >> n >> m >> a >> b;
    vector<node> s;
    for (int i = 0; i < m; i++)
    {
        ll L, R;
        cin >> L >> R;
        s.push_back(node(L, R));
    }
    sort(s.begin(), s.end(), [](const node &a, const node &b)
         { return a.x < b.x; });
    vector<node> p;
    for (const auto &v : s)
    {
        if (p.empty() || !check(p.back(), v))
            p.push_back(v);
        else
            p.back() = merge(p.back(), v);
    }
    vector<node> q;
    q.push_back(node(1, 1));
    while (!q.empty())
    {
        vector<node> k;
        for (const auto &v : q)
        {
            for (ll mv = a; mv <= b; ++mv)
            {
                ll st = v.y + mv;
                ll ed = st + b - a;
                if (ed >= n)
                {
                    cout << "Yes" << endl;
                    return 0;
                }
                bool flag = 0;
                for (const auto &v : p)
                    if (check(node(st, ed), v))
                    {
                        flag = 1;
                        break;
                    }
                if (!flag)
                    k.push_back(node(st, ed));
            }
        }
        q = move(k);
    }
    cout << "No" << endl;
    return 0;
}
