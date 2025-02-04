#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
ll n, m;
char a[1001][1001], b[1001][1001];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
            cin >> b[i][j];
    for (int l = 1; l <= n - m + 1; l++)
        for (int r = 1; r <= n - m + 1; r++)
        {
            for (int i = 1; i <= m; i++)
                for (int j = 1; j <= m; j++)
                    if (a[l + i - 1][r + j - 1] != b[i][j])
                        goto nxt;
            cout << l << ' ' << r;
            return 0;
        nxt:;
        }
    return 0;
}