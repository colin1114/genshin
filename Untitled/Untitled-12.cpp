#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
ll n, p, h, m;
PII a[E];
ll sum[E];
int main()
{
    cin >> n >> p >> h >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].x >> a[i].y;
        if (a[i].x > a[i].y)
            swap(a[i].x, a[i].y);
        bool flag = 1;
        for (int j = 1; j < i; j++)
            if (a[i].x == a[j].x && a[i].y == a[j].y)
            {
                flag = 0;
                break;
            }
        if (flag)
            sum[a[i].x + 1]--, sum[a[i].y]++;
    }
    for (int i = 1; i <= n; i++)
        sum[i] += sum[i - 1];
    for (int i = 1; i <= n; i++)
        cout << sum[i] + h << endl;
    return 0;
}