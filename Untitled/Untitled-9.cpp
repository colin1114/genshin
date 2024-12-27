#include <bits/stdc++.h>
#define ll long long

#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
ll n, m;
ll sum[E], a[E];
int main()
{
    cin >> n >> m;
    while (m--)
    {
        ll l, r;
        cin >> l >> r;
        sum[l] += 1;
        sum[r + 1] -= 1;
    }
    ll sum1 = 0;
    for (int i = 1; i <= n; i++)
        sum1 += sum[i], a[i] = sum1;
    sort(a + 1, a + 1 + n);
    cout << a[n / 2];
    return 0;
}