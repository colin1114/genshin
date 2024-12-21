#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;
ll a, b, c;
int main()
{
    cin >> a >> b >> c;
    if (a == b && b == c && c == a)
        cout << "Yes";
    else if (a + b == c || a + c == b || b + c == a)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}