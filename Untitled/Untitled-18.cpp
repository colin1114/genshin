#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
const ll mod = 1e9 + 7;
ll n;
bitset<E> vis;
ll prime[E];
inline void init()
{
    vis[1] = 1;
    for (int i = 2; i * i <= n; i++)
        if (!vis[i])
            for (int j = i * 2; j <= n; j += i)
                vis[j] = 1;
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            prime[++prime[0]] = i;
}
int main()
{
    cin >> n;
    init();
    cerr << "OK 1\n";
    ll ans = 1;
    for (int i = 1; i <= prime[0]; i++)
    {
        cerr << "OK 2\n";
        ll s = 0;
        for (int j = n; j; j /= prime[i])
            s += j / prime[i];
        cerr << "OK 3\n";
        ans = ans * (2 * s + 1) % mod;
    }
    cout << endl;
    
    return 0;
}