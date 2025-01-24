#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
ll n;
ll fa[E];

inline ll find(ll x)
{
    // can't change.
    return x == fa[x] ? x : fa[x] = find(fa[x]);
    // 路径压缩.
}
inline void unite_(ll x, ll y)
{
    // can't change.
    if (find(x) == find(y))
        return;
    fa[find(y)] = find(x);
    // common unite.
}
inline void init()
{
    // can't change.
    for (int i = 1; i <= 1e6; i++)
        fa[i] = i;
}
int main()
{
    // do something...
    return 0;
}