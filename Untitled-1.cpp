#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
ll n, cnt;
ll bit[E];
struct node
{
    ll a, b, c;
};
inline void update(ll x, ll v) 
{
    for (ll i = x; i <= n; i += i & -i)
        bit[i] = min(bit[i], v);
}
inline ll query(ll x) 
{
    ll res = 1e18;
    for (ll i = x; i > 0; i -= i & -i)
        res = min(res, bit[i]);
    return res;
}
int main(){
    cin >> n;
    vector<node> t(n + 1);
    ll x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        t[x - 1].a = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> x;
        t[x - 1].b = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> x;
        t[x - 1].c = i;
    }
    sort(t.begin(), t.begin() + n, [&](const node& x, const node& y) {
        return x.a < y.a;
    });
    fill(bit + 1, bit + n + 1, 1e18);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll x = query(t[i].b);
        if (x > t[i].c) 
            ans++;
        update(t[i].b + 1, t[i].c);
    }
    cout << ans << endl;
    return 0;
}