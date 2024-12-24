#include <bits/stdc++.h>
#define ll unsigned long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
ll n, h;
bool vis[E];
struct node
{
    ll x, y, z;
} a[E];
inline bool cmp(node a, node b)
{
    return a.y < b.y;
}
int main()
{
    cin >> n >> h;
    for (int i = 1; i <= h; i++)
        cin >> a[i].x >> a[i].y >> a[i].z;
    sort(a + 1, a + 1 + h, cmp);
    ll ans = 0;
    for (int i = 1; i <= h; i++)
    {
        ll cnt = 0;
        for (int j = a[i].x; j <= a[i].y; j++)
            if (vis[j])
                cnt++;
        if (cnt >= a[i].z)
            continue;
        for (int j = a[i].y; j >= a[i].x; j--)
            if (!vis[j])
            {
                vis[j] = 1;
                cnt++, ans++;
                if (cnt == a[i].z)
                    break;
            }
    }
    cout << ans;
    return 0;
}   