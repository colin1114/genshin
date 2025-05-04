#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
ll t, n;
ll a[E], sum[E];
int main()
{
    freopen("array.in", "r", stdin);
    freopen("array.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        fill(sum, sum + 2 + n, 0);
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
        }
        ll max1 = sum[n];
        for (int i = 1; i <= n; i++)
            if (sum[n] - sum[i] > 0)
                max1 += sum[n] - sum[i];
        cout << max1 << endl;
    }
    return 0;
}