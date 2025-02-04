#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
ll n;
ll a[E], b[E];
ll sum = 0;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        sum += b[i];
        if (a[i] + sum >= n - i - 1)
        {
            a[i] -= n - i - 1;
            b[i + 1]++;
            b[n]--;
        }
        else
        {
            b[i + 1]++;
            b[i + a[i] + sum + 1]--;
            a[i] -= a[i] + sum;
        }
    }
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += b[i];
        cout << a[i] + sum << " ";
    }
    return 0;
}