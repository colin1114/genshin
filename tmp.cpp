#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
ll t;
ll m, a, b, c;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> m >> a >> b >> c;
        if (m <= a && m <= b)
            cout << 2 * m << endl;
        else if (m < a && m > b)
            cout << m + b + max(((m - b) > c ? c : (m - b)), 0LL) << endl;
        else if (m > a && m < b)
            cout << m + a + max(((m - a) > c ? c : (m - a)), 0LL) << endl;
        else if (m > a && m > b)
            cout << a + b + max(((2 * m - (a + b)) > c ? c : (2 * m - (a + b))), 0LL) << endl;
    }
    return 0;
}