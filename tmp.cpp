#include <bits/stdc++.h>
#define endl '\n'

#define ll int

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
ll n, m, q;
ll a[5005][5005], ans[5005][5005];  
int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    // freopen("hack.in", "r", stdin);
    // freopen("hack.out", "w", stdout);
    cin >> n >> q;
    m = n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            ans[i][j] += a[i][j];
            ans[i + 1][j + 1] += a[i][j];
            ans[i][j + 1] -= a[i][j];
            ans[i + 1][j] -= a[i][j];
        }
    while (q--)
    {
        ll a, b, c, d, s;
        cin >> a >> b >> c >> d;
        s = 1;
        ans[a][b] += s;
        ans[c + 1][d + 1] += s;
        ans[a][d + 1] -= s;
        ans[c + 1][b] -= s;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            ans[i][j] += ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1], cout << ans[i][j] << ' ';
        cout << endl;
    }
    return 0;
}