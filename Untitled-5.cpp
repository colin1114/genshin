#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

string s;

int main()
{
    // freopen("1.txt", "r", stdin);
    // freopen("ams.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    while (cin >> s && s != ".")
    {
        int n = s.size();
        vector<int> nxt(n + 1);
        nxt[0] = -1;
        int i = 0, j = -1;
        while (i < s.size())
        {
            if (j == -1 || s[i] == s[j])
            {
                i++;
                j++;
                nxt[i] = j;
            }
            else
                j = nxt[j];
        }
        cout << n / (n - nxt[n]) << endl;
    }

    return 0;
}
