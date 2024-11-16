#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
string a, b;
ll ans;
inline void get_nxt(string &s, vector<ll> &nxt)
{
    nxt.resize(s.size());
    nxt[0] = -1;
    ll i = 0, j = -1;
    while (i < s.length())
    {
        if (j == -1 || s[i] == s[j])
        {
            i++;
            j++;
            if (s[i] == s[j])
                nxt[i] = nxt[j];
            else
                nxt[i] = j;
        }
        else
            j = nxt[j];
    }
}
inline ll kmp(string &f, string &s, const vector<ll> &nxt)
{
    ll i = 0, j = 0;
    while (i < f.size())
    {
        if (j == -1 || f[i] == s[j])
        {
            i++;
            j++;
            if (j == s.size())
                return (i - s.size());
        }
        else
            j = nxt[j];
    }
    return -1;
}
int main()
{
    cin >> a >> b;
    vector<ll> nxt(b.size() + 1);
    get_nxt(b, nxt);
    ll x = kmp(a, b, nxt);
    cout << (x != -1 ? "yes\n" : "no\n");
    if (x != -1)
        cout << x;
    return 0;
}