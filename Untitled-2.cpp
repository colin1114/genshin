#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
ll t;
ll x;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> x;
        if (x <= 4)
        {
            cout << -1 << endl;
            continue;
        }
        for (int i = 2; i <= x; i += 2)
            if (i != 4)
                cout << i << ' ';
        cout << "4 5 ";
        for (int i = 1; i <= x; i += 2)
            if (i != 5)
                cout << i << ' ';
        cout << endl;
    }
    return 0;
}