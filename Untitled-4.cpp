#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;

int main()
{
    ll t;
    cin >> t;
    while (t--) {
        ll n, m, q;
        cin >> n >> m >> q;
        
        vector<ll> a(n), b(m);
        for (auto &v : a) cin >> v;
        for (auto &v : b) cin >> v;

        vector<pair<ll, ll>> merge;
        for (auto v : a) merge.push_back({v, 1});
        for (auto v : b) merge.push_back({v, 2});
        sort(merge.begin(), merge.end(), greater<pair<ll, ll>>());

        vector<ll> p(n + m), q_(n + m);
        ll cnt = 0, cnt1 = 0;
        for (int i = 0; i < n + m; i++) {
            if (merge[i].y == 1) cnt++;
            else cnt1++;
            p[i] = cnt, q_[i] = cnt1;
        }

        sort(a.begin(), a.end(), greater<ll>());
        sort(b.begin(), b.end(), greater<ll>());
        vector<ll> sum(n), sum1(m);
        for (int i = 0; i < n; i++) sum[i] = (i == 0 ? a[i] : sum[i - 1] + a[i]);
        for (int i = 0; i < m; i++) sum1[i] = (i == 0 ? b[i] : sum[i - 1] + b[i]);

        auto check = [&](ll mid, ll x, ll y, ll z) -> bool {
            return min(p[mid], x) + min(q_[mid], y) <= z;
        };

        while (q--) {
            ll x, y, z;
            cin >> x >> y >> z;
            ll l = 0, r = n + m - 1, ans = -1;
            while (l <= r) {
                ll mid = l + r >> 1;
                if (check(mid, x, y, z)) r = mid - 1, ans = mid;
                else l = mid + 1;
            }
            if (ans == -1) {
                cout << 0 << endl;
                continue;
            }
            l = min(p[ans], x) - 1, r = min(q_[ans], y) - 1;
            l = max(l, 0LL), r = max(r, 0LL);
            cout << sum[l] + sum[r] << endl;
        }
    }
    return 0;
}