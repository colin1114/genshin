#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
ll n, m;
ll x[E], y[E], x_[E], y_[E];
int main()
{
    freopen("cake.in", "r", stdin);
    freopen("cake.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ll x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        ll x_min = min({x1, x2, x3});
        ll x_max = max({x1, x2, x3});
        ll y_min = min({y1, y2, y3});
        ll y_max = max({y1, y2, y3});
        if (x_min < x_max)
        {
            x[x_min + 1]++;
            x[x_max]--;
        }
        if (y_min < y_max)
        {
            y[y_min + 1]++;
            y[y_max]--;
        }
    }
    for (int i = 1; i < E; i++)
    {
        x_[i] = x_[i - 1] + x[i];
        y_[i] = y_[i - 1] + y[i];
    }
    cin >> m;
    while (m--)
    {
        char op, tmp;
        ll c;
        cin >> op >> tmp >> c;
        if (op == 'x')
            cout << x_[c] << endl;
        else
            cout << y_[c] << endl;
    }
    return 0;
}
