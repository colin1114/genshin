#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
ll n, m, x, y;
char a[1001][1001];
map<PII, bool> mp;
ll ans = 0;
int main()
{
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    string s;
    cin >> s;
    ll len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'D')
            x++;
        if (s[i] == 'U')
            x--;
        if (s[i] == 'R')
            y++;
        if (s[i] == 'L')
            y--;
        if (a[x][y] == '#')
        {
            if (s[i] == 'D')
                x--;
            if (s[i] == 'U')
                x++;
            if (s[i] == 'R')
                y--;
            if (s[i] == 'L')
                y++;
            continue;
        }
        else if (a[x][y] == '.')
            continue;
        else
        {
            if (!mp[{x, y}])
                ans++;
            mp[{x, y}] = 1;
        }
    }
    cout << x << ' ' << y << ' ' << ans;
    return 0;
}