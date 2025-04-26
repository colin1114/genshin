#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
ll n;
ll a[E], cnt[E];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll max1 = 0;
    for (int i = 1; i <= n; i++)
        cnt[a[i]]++, max1 = max(max1, a[i]);
    for (int i = max1; i >= 1; i--)
    {
        ll sum = 0;
        for (int j = i; j <= max1; j += i)
            sum += cnt[j];
        if (sum >= 2)
        {
            cout << i;
            return 0;
        }
    }
    return 0;
}
