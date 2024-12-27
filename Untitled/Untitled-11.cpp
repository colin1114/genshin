#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
ll n;
PII a[E];
bool flag[E], flag1[E];
ll p[E];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    ll cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        if (p[i] < 0)
            cnt *= -1;
        if (cnt == 1)
            flag[i] = 1;
        else
            flag[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        a[i].x = a[i - 1].x;
        a[i].y = a[i - 1].y;
        if (flag[i] > 0)
            a[i].x++;
        else
            a[i].y++;
    }
    ll ans = 0, ans1 = 0;
    for (int i = 1; i <= n; i++)
        if (flag[i])
            ans += a[i - 1].x, ans1 += a[i - 1].y;
        else
            ans += a[i - 1].y, ans1 += a[i - 1].x;
    cout << ans1 + a[n].y << ' ' << ans + a[n].x;
    return 0;
}