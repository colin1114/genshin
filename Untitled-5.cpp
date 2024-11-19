#include <bits/stdc++.h>
#define ll unsigned long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
ll base[E], hsh1[E];
ll hsh[300][500];
ll ln[E];
ll dp[E];
inline ll get(ll l, ll r, ll x)
{
    return hsh[x][r] - hsh[x][l - 1] * base[r - l + 1];
}
inline ll get1(ll l, ll r)
{
    return hsh1[r] - hsh1[l - 1] * base[r - l + 1];
}
int main()
{
    base[0] = 1;
    for (int i = 1; i <= 1e6; i++)
        base[i] = base[i - 1] * 31;
    string s;
    ll cnt = 0;
    while (cin >> s)
    {
        if (s == ".")
            break;
        ll len = s.length();
        ln[++cnt] = len;
        for (int i = 1; i <= len; i++)
            hsh[cnt][i] = hsh[cnt][i - 1] * 31 + s[i - 1];
    }
    string t = "", tmp;
    while (cin >> tmp)
        t += tmp;
    ll len = t.length();
    for (int i = 1; i <= len; i++)
        hsh1[i] = hsh1[i - 1] * 31 + t[i - 1];
    for (int i = 0; i < len; i++)
    {
        if (i == 0 || dp[i - 1] > 0)
        {
            for (int j = 1; j <= cnt; j++)
            {
                if (ln[j] + i > len)
                    continue;
                if (get1(i + 1, i + ln[j]) == get(1, ln[j], j))
                    dp[i + ln[j] - 1] = 1;
            }
        }
    }
    for (int i = len - 1; i >= 0; i--)
        if (dp[i])
        {
            cout << i + 1 << endl;
            return 0;
        }
    cout << 0;
    return 0;
}