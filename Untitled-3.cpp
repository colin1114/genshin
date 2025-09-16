#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
ll t, n;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        ll all_gcd = a[1];
        for (int i = 2; i <= n; i++)
            all_gcd = __gcd(all_gcd, a[i]);
        // cerr << all_gcd << endl;
        ll ans = 0;
        bool flag = 0;
        for (int i = 1; i <= n; i++)
            if (a[i] == all_gcd)
            {
                flag = 1;
                break;
            }
        if (flag)
        {
            for (int i = 1; i <= n; i++)
                if (a[i] != all_gcd)
                    ans++;
            cout << ans << endl;
            continue;
        }
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                if (__gcd(a[i], a[j]) == all_gcd)
                {
                    flag = 1;
                    break;
                }
        if (flag)
        {
            cout << n << endl;
            continue;
        }
        ll max1 = 0, min1 = 1e18, p = 0, q = 0;
        for (int i = 1; i <= n; i++)
        {
            
            for (int j = i + 1; j <= n; j++)
                if (__gcd(a[i], a[j]) == all_gcd)
                {
                    ans++;
                    a[i] = all_gcd;
                    goto con;
                }
            for (int j = 1; j <= n; j++)
                if (__gcd(a[p], a[j]) == all_gcd && p != j)
                {
                    ans++;
                    a[p] = all_gcd;
                    goto con;
                }
            max1 = 0, min1 = 1e18;
            for (int j = 1; j <= n; j++)
            {
                if (a[j] > max1)
                    p = j, max1 = a[j];
                if (a[j] < min1)
                    q = j, min1 = a[j];
            }
            // cerr << p << ' ' << q << endl;
            a[p] = __gcd(a[p], a[q]);
            // for (int j = 1; j <= n; j++)
            //     cerr << a[j] << ' ';
            // cerr << endl;
            ans++;
        }
        con:;
        for (int i = 1; i <= n; i++)
            if (a[i] != all_gcd)
                ans++;
        cout << ans << endl;
    }
    return 0;
}

