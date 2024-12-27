#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;
const int E = 1e6 + 5;
ll n;
ll fa[E];
inline ll find(ll x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
inline void unite(ll x, ll y)
{
    if (find(x) == find(y))
        return;
    fa[find(y)] = find(x);
}
int main()
{
    
    return 0;
}