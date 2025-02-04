#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
ll n, q;
ll id[E], a[E];
int main()
{
    cin >> n >> q;
    ll cnt = 0;
    fill(a + 1, a + 1 + n, 1);
    for (int i = 1; i <= n; ++i)
        id[i] = i;
    while (q--)
    {
        ll op;
        cin >> op;
        if (op == 1)
        {
            ll p, h;
            cin >> p >> h;
            a[id[p]]--;
            if (a[id[p]] == 1)
                cnt--;
            id[p] = h;
            a[h]++;
            if (a[h] == 2)
                cnt++;
        }
        else if (op == 2)
            cout << cnt << endl;
    }
    return 0;
}