#include <bits/stdc++.h>
#define ll unsigned long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
const int Base = 31;
string a, b;
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
    int i = 0, j = 0;
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
    // cout << ans;
    return -1;
}
int main()
{
    cin >> a >> b;
    ll len1 = b.length();
    ll len = a.length();
    vector<ll> nxt(b.size() + 1);
    get_nxt(b, nxt);
    while (1)
    {
    con:;
        ll x = kmp(a, b, nxt);
        if (x == -1)
            break;
        bitset<E> vis;
        for (int i = 0; i < len1; i++)
            vis[i + x] = 1;
        string tmp = "";
        for (int i = 0; i < len; i++)
            if (!vis[i])
                tmp += a[i];
        a = tmp;
        len -= len1;
        goto con;
    }
    cout << a;
    return 0;
}