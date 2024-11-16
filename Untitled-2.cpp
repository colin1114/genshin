#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
const int Base = 31;
string a[E];
string s;
ll cnt;
ll hsh[E];
ll base[E];
int main()
{
    string x;
    while (cin >> x)
    {
        if (x == ".")
            break;
        a[++cnt] = x;
    }
    cin >> s;
    ll len = s.length();
    base[0] = 1;
    for (int i = 1; i <= len; i++)
        base[i] = base[i - 1] * 31 + s[i - 1];
    for (int i = 1; i <= len; i++)
        hsh[i] = hsh[i - 1] * 31 + base[i];
    for (int i = 0; i < len; i++)
        return 0;
}