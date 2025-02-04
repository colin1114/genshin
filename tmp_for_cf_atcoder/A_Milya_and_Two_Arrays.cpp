#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;
const int E = 1e6 + 5;
ll t, n;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<ll> a(n), b(n);
        for (auto &x : a)
            cin >> x;
        for (auto &x : b)
            cin >> x;
        unordered_set<ll> st, st1;
        for (auto &x : a)
            st.insert(x);
        for (auto &x : b)
            st1.insert(x);
        ll len = st.size(), len1 = st1.size();
        if ((len >= 2 && len1 >= 2) || (len == 1 && len1 >= 3) || (len1 == 1 && len >= 3))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
