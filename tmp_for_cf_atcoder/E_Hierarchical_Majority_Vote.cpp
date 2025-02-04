#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

#define PII pair<ll, ll>
#define x first
#define y second

using namespace std;
const int E = 1e6 + 5;

struct node
{
    ll x, y, rt;
};

string a;
ll n;
inline node dfs(ll st, ll len)
{
    if (len == 1)
    {
        node leaf;
        if (a[st] == '0')
        {
            leaf.x = 0;
            leaf.y = 1;
            leaf.rt = 0;
        }
        else
        {
            leaf.x = 1;
            leaf.y = 0;
            leaf.rt = 1;
        }
        return leaf;
    }
    ll seg = len / 3;
    node left = dfs(st, seg);
    node mid = dfs(st + seg, seg);
    node right = dfs(st + 2 * seg, seg);
    node ret;
    ll sumBits = left.rt + mid.rt + right.rt;
    ret.rt = (sumBits >= 2) ? 1 : 0;
    ll c0 = 1e18;
    c0 = min(c0, left.x + mid.x + right.x);
    c0 = min(c0, left.x + mid.x + right.y);
    c0 = min(c0, left.x + mid.y + right.x);
    c0 = min(c0, left.y + mid.x + right.x);
    ret.x = c0;
    ll c1 = 1e18;
    c1 = min(c1, left.y + mid.y + right.x);
    c1 = min(c1, left.y + mid.x + right.y);
    c1 = min(c1, left.x + mid.y + right.y);
    c1 = min(c1, left.y + mid.y + right.y);
    ret.y = c1;

    return ret;
}

int main()
{
    cin >> n;
    cin >> a;
    node rt = dfs(0, a.size());
    cout << ((rt.rt == 0) ? rt.y : rt.x);
    return 0;
}