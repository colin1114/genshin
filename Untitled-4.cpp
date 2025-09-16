#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
const int N = 3e5 + 7;
ll a[N], b[N], c[N], t[N], n, k;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    priority_queue<pll, vector<pll>, greater<pll>> pque;
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        t[i] = max(t[i - 1], a[i]);
        while (k < c[i] && pque.size()) {
            auto [e, p] = pque.top();
            pque.pop();
            k += p, t[i] = max(t[i], e);
        }
        k -= c[i];
        pque.emplace(t[i] + b[i], c[i]);
        cout << t[i] << '\n';
    }
    return 0;
}
