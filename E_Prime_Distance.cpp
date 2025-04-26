#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
vector<ll> primes;
bitset<E> vis;
inline void init()
{
    vis.set();
    vis[0] = vis[1] = 0;
    for (ll i = 2; i * i < E; i++)
        if (vis[i])
            for (ll j = i * i; j < E; j += i)
                vis[j] = 0;
    for (int i = 2; i < E; i++)
        if (vis[i])
            primes.push_back(i);
}
int main()
{
    init();
    ll l, r;
    while (cin >> l >> r)
    {
        ll len = r - l + 1;
        vector<bool> flag(len, 1);
        if (l == 1)
        {
            if (len > 0)
                flag[0] = 0;
            else
            {
                cout << "There are no adjacent primes.\n";
                continue;
            }
        }
        for (auto v : primes)
        {
            if (v * v > r)
                break;
            ll st = max(v * v, (l + v - 1) / v * v);
            for (ll j = st; j <= r; j += v)
                if (j >= l)
                    flag[j - l] = 0;
        }
        vector<ll> p;
        for (ll i = 0; i < len; ++i)
            if (flag[i])
                p.push_back(l + i);

        if (p.size() < 2)
            cout << "There are no adjacent primes." << endl;
        else
        {
            ll min1 = numeric_limits<ll>::max();
            ll max1 = 0;
            ll c1 = -1, c2 = -1;
            ll d1 = -1, d2 = -1;
            for (int i = 0; i < p.size() - 1; ++i)
            {
                ll p_curr = p[i];
                ll p_next = p[i + 1];
                ll diff = p_next - p_curr;
                if (diff < min1)
                {
                    min1 = diff;
                    c1 = p_curr;
                    c2 = p_next;
                }
                if (diff > max1)
                {
                    max1 = diff;
                    d1 = p_curr;
                    d2 = p_next;
                }
            }
            cout << c1 << "," << c2 << " are closest, " << d1 << "," << d2 << " are most distant.\n";
        }
    }

    return 0;
}
