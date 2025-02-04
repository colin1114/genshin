#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
string s;
int main()
{
    cin >> s;
    for (auto &v : s)
    {
        if (v == 'N')
            v = 'S';
        else if (v == 'S')
            v = 'N';
        else if (v == 'W')
            v = 'E';
        else if (v == 'E')
            v = 'W';
    }
    cout << s << endl;
    return 0;
}