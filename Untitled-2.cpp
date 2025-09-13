#include <bits/stdc++.h>
#define ll long long
#define db double
#define uint unsigned int
#define ull unsigned long long
// #define int ll

#define pii pair<int, int>
#define pll pair<ll, ll>

#define endl "\n"
#define all(x) x.begin(), x.end()
#define all1(x) x.begin() + 1, x.end()

// #define x first
// #define y second

using namespace std;

const int inf = 2e9;
const ll INF = 2e18;
const int mod = 1e9 + 7;
const db eps = 1e-7;
const int maxn = 1e5 + 5;
const int N = 1e7 + 5;

void solve() {
    string a, b;
    cin >> a >> b;
    vector<int> cnt1(26, 0), cnt2(26, 0);
    for (auto v : a) cnt1[v - 'a'] += 1;
    for (auto v : b) cnt2[v - 'a'] += 1;

    vector<int> ans(26, 0);
    int curr = 0, tot = 0;
    for (int i = 0; i < 26; i++) if (!cnt2[i] && cnt1[i]) curr += 1, ans[i] = 1;

    // for (int i = 0; i < 26; i++) cerr << cnt1[i] << ' ';
    // cerr << endl;

    if (curr <= 1) {
        cout << -1 << endl;
        return;
    }
    int cnt = 0;
    int p1 = -1, p2 = -1;
    for (int i = 0; i < 26; i++) if (ans[i]) p1 = p2, p2 = i;
    for (int i = 0; i < 26; i++) {
        if (i == p1 || i == p2) {
            if (cnt == 0)
                for (int j = 1; j <= cnt1[i] - ((cnt1[i] & 1) ^ 1); j++) cout << (char)('a' + i);
            else 
                cout << (char)('a' + i);
            cnt += 1;
        }
        else if (cnt == 0 || !ans[i]) {
            for (int j = 1; j <= cnt1[i]; j++) cout << (char)('a' + i);
            if (ans[i] && cnt1[i] % 2) cnt += 1;
        }
        else cout << (char)('a' + i), cnt += 1;
        if (cnt == 2) break;
    }
    cout << endl;
}

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}