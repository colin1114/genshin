#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
ll n;
string s;
inline void get_nxt(string &s, vector<ll> &nxt)
{
    nxt.resize(s.size() + 5);
    nxt[1] = 0;
    ll j = 0;
    for (int i = 2; i <= n; i++)
    {
        while (j > 0 && s[j + 1] != s[i])
            j = nxt[j];
        if (s[j + 1] == s[i])
            j++;
        nxt[i] = j;
    }
}
int main()
{
    ll cnt = 0;
    while (1)
    {
        vector<ll> nxt;
        cin >> n;
        if (n == 0)
            break;
        cin >> s;
        s = ' ' + s;
        get_nxt(s, nxt);
        cout << "Test case #" << ++cnt << endl;
        for (int i = 2; i <= n; i++)
            if (i % (i - nxt[i]) == 0 && i / (i - nxt[i]) > 1)
                cout << i << ' ' << i / (i - nxt[i]) << endl;
        cout << endl;
    }
    return 0;
}