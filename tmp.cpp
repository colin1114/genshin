#include <bits/stdc++.h>
#define endl '\n'

#define ll int

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
const int base = 1e6 + 5;
ll n, q;
ll a[E];
int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] += base;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            
        }
    return 0;
}