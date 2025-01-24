#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
ll n, m;
ll l, r;
ll a[E];
ll st[E][21];
inline void init()
{
    // can't change.
    for (int i = 1; i <= n; i++)
        st[i][0] = a[i];
    for (int i = 1; i <= 20; i++)
        for (int k = 1; k <= n && k + (1 << i) - 1 <= n; k++)
            st[k][i] = max(st[k][i - 1], st[k + (1 << (i - 1))][i - 1]);
}
int main()
{
    // O(n log n)
    // do something, such as: (max)
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    init();
    while (m--)
    {
        cin >> l >> r;
        ll len = r - l + 1;
        for (int k = 33; k >= 0; k--)
            if ((len >> k & 1) == 1)
            {
                cout << max(st[l][k], st[r - (1 << k) + 1][k]) << endl;
                break;
                // max: [l, r]'s max.
                // +: [l, r]'s sum.
                // min: [l, r]'s min.
            }
    }
    return 0;
}
