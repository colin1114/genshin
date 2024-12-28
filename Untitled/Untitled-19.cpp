#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
const ll mod1 = 1000000007;
const ll mod2 = 1000000009;
const ll base1 = 911382629;
const ll base2 = 972663749;
inline ll ksm(ll base, ll exp, ll mod)
{
    ll ans = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)
            ans = (ans * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return ans;
}
ll m, n, A, b, q;
string a[E];
ll pow1_B[E], pow2_B[E];
ll pow1_A[E], pow2_A[E];
ll hash1[1005][1005], hash2[1005][1005];
string qry[E];
ll hash_qry1[1005], hash_qry2[1005];
int main()
{
    cin >> m >> n >> A >> b;
    for (int i = 0; i < m; i++)
        cin >> a[i];
    pow1_B[0] = pow2_B[0] = pow1_A[0] = pow2_A[0] = 1;
    for (int i = 1; i < b; i++)
        pow1_B[i] = (pow1_B[i - 1] * base1) % mod1, pow2_B[i] = (pow2_B[i - 1] * base2) % mod2;
    for (int i = 1; i < A; i++)
        pow1_A[i] = (pow1_A[i - 1] * base1) % mod1, pow2_A[i] = (pow2_A[i - 1] * base2) % mod2;
    for (int i = 0; i < m; i++)
    {
        ll h1 = 0, h2 = 0;
        for (int j = 0; j < b; j++)
        {
            h1 = (h1 * base1 + (a[i][j] - '0' + 1)) % mod1;
            h2 = (h2 * base2 + (a[i][j] - '0' + 1)) % mod2;
        }
        hash1[i][0] = h1;
        hash2[i][0] = h2;
        for (int j = 1; j <= n - b; j++)
        {
            h1 = (h1 - ((a[i][j - 1] - '0' + 1) * ksm(base1, b - 1, mod1)) % mod1 + mod1) % mod1;
            h1 = (h1 * base1 + (a[i][j + b - 1] - '0' + 1)) % mod1;
            h2 = (h2 - ((a[i][j - 1] - '0' + 1) * ksm(base2, b - 1, mod2)) % mod2 + mod2) % mod2;
            h2 = (h2 * base2 + (a[i][j + b - 1] - '0' + 1)) % mod2;
            hash1[i][j] = h1;
            hash2[i][j] = h2;
        }
    }
    unordered_set<ll> st;
    for (int j = 0; j <= n - b; j++)
    {
        ll h1 = 0, h2 = 0;
        for (int i = 0; i < A; i++)
            h1 = (h1 * base1 + hash1[i][j]) % mod1, h2 = (h2 * base2 + hash2[i][j]) % mod2;
        ll x = h1 * mod2 + h2;
        st.insert(x);
        for (int i = 1; i <= m - A; i++)
        {
            h1 = (h1 - (hash1[i - 1][j] * ksm(base1, A - 1, mod1)) % mod1 + mod1) % mod1;
            h1 = (h1 * base1 + hash1[i + A - 1][j]) % mod1;
            h2 = (h2 - (hash2[i - 1][j] * ksm(base2, A - 1, mod2)) % mod2 + mod2) % mod2;
            h2 = (h2 * base2 + hash2[i + A - 1][j]) % mod2;
            x = h1 * mod2 + h2;
            st.insert(x);
        }
    }
    cin >> q;
    while (q--)
    {
        for (int i = 0; i < A; i++)
            cin >> qry[i];
        for (int i = 0; i < A; i++)
        {
            ll h1 = 0, h2 = 0;
            for (int j = 0; j < b; j++)
                h1 = (h1 * base1 + (qry[i][j] - '0' + 1)) % mod1, h2 = (h2 * base2 + (qry[i][j] - '0' + 1)) % mod2;
            hash_qry1[i] = h1;
            hash_qry2[i] = h2;
        }
        ll ans = 0, ans1 = 0;
        for (int i = 0; i < A; i++)
        {
            ans = (ans * base1 + hash_qry1[i]) % mod1;
            ans1 = (ans1 * base2 + hash_qry2[i]) % mod2;
        }
        ll x = ans * mod2 + ans1;
        if (st.find(x) != st.end())
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
