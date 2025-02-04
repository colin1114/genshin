#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;

int op(int a, int b)
{
    return max(a, b);
}
int e()
{
    return -1;
}
int target;
bool f(int y)
{
    return y < target;
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a.at(i);
    segtree<int, op, e> seg(a);
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x, v;
            cin >> x >> v;
            x--;
            seg.set(x, v);
        }
        else if (t == 2)
        {
            int l, r;
            cin >> l >> r;
            l--;
            cout << seg.prod(l, r) << endl;
        }
        else
        {
            int x;
            cin >> x >> target;
            x--;
            cout << seg.max_right<f>(x) + 1 << endl;
        }
    }
}