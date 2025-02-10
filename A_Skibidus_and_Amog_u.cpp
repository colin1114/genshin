#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
ll t;
int main()
{
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        ll len = s.length();
        for (int i = 0; i < len - 2; i++)
            cout << s[i];
        cout << 'i' << endl;
    }
    return 0;
}