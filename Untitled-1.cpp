#include <bits/stdc++.h>
#define ll unsigned long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
const int Base = 31;
string a, b;
int main()
{
    cin >> a >> b;
    ll len1 = b.length();
    ll len = a.length();
    while (1)
    {
    con:;
        ll x = a.find(b);
        if (x == string::npos)
            break;
        bitset<E> vis;
        for (int i = 0; i < len1; i++)
            vis[i + x - 1] = 1;
        string tmp = "";
        for (int i = 0; i < len; i++)
            if (!vis[i])
                tmp += a[i];
        a = tmp;
        len = a.length();
        goto con;
    }
    cout << a;
    return 0;
}