#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 3e6 + 5;
struct Node
{
    int lef;
    int rig;
    int maxn;
    int lmax;
    int rmax;
    int aim;
} Tree[N];
void pushup(int now)
{
    Tree[now].maxn = max(max(Tree[now << 1].maxn, Tree[now << 1 | 1].maxn), Tree[now << 1].rmax + Tree[now << 1 | 1].lmax);
    Tree[now].lmax = Tree[now << 1].lmax;
    if (Tree[now << 1].lmax == Tree[now << 1].rig - Tree[now << 1].lef + 1)
        Tree[now].lmax += Tree[now << 1 | 1].lmax;
    Tree[now].rmax = Tree[now << 1 | 1].rmax;
    if (Tree[now << 1 | 1].rmax == Tree[now << 1 | 1].rig - Tree[now << 1 | 1].lef + 1)
        Tree[now].rmax += Tree[now << 1].rmax;
}
void build(int now, int l, int r)
{
    Tree[now].lef = l;
    Tree[now].rig = r;
    Tree[now].aim = -1;
    if (l == r)
    {
        Tree[now].maxn = Tree[now].lmax = Tree[now].rmax = 1;
        return;
    }
    int mid = l + r >> 1;
    build(now << 1, l, mid);
    build(now << 1 | 1, mid + 1, r);
    pushup(now);
}
void pushdown(int now)
{
    if (Tree[now].aim != -1)
    {
        if (Tree[now].aim == 0)
        {
            Tree[now << 1].maxn = Tree[now << 1].lmax = Tree[now << 1].rmax = Tree[now << 1].rig - Tree[now << 1].lef + 1;
            Tree[now << 1 | 1].maxn = Tree[now << 1 | 1].lmax = Tree[now << 1 | 1].rmax = Tree[now << 1 | 1].rig - Tree[now << 1 | 1].lef + 1;
        }
        else
        {
            Tree[now << 1].maxn = Tree[now << 1].lmax = Tree[now << 1].rmax = 0;
            Tree[now << 1 | 1].maxn = Tree[now << 1 | 1].lmax = Tree[now << 1 | 1].rmax = 0;
        }
        Tree[now << 1].aim = Tree[now << 1 | 1].aim = Tree[now].aim;
        Tree[now].aim = -1;
    }
}
void modify(int now, int l, int r, int x)
{
    if (l <= Tree[now].lef && Tree[now].rig <= r)
    {
        Tree[now].aim = x;
        if (x == 1)
            Tree[now].maxn = Tree[now].lmax = Tree[now].rmax = 0;
        else
            Tree[now].maxn = Tree[now].lmax = Tree[now].rmax = Tree[now].rig - Tree[now].lef + 1;
        return;
    }
    pushdown(now);
    int mid = Tree[now].lef + Tree[now].rig >> 1;
    if (l <= mid)
        modify(now << 1, l, r, x);
    if (r > mid)
        modify(now << 1 | 1, l, r, x);
    pushup(now);
}
int query(int now, int x)
{
    pushdown(now);
    if (Tree[now].maxn < x)
        return Tree[now].rig - Tree[now].rmax + 1;
    if (Tree[now << 1].maxn >= x)
        return query(now << 1, x);
    else if (Tree[now << 1].rmax + Tree[now << 1 | 1].lmax >= x)
        return query(now << 1, x);
    else if (Tree[now << 1 | 1].maxn >= x)
        return query(now << 1 | 1, x);
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    build(1, 1, n);
    int cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        char op[2];
        scanf("%s", op);
        if (*op == 'A')
        {
            int x;
            scanf("%d", &x);
            if (Tree[1].maxn >= x)
            {
                int left = query(1, x);
                modify(1, left, left + x - 1, 1);
            }
            else
                cnt++;
        }
        else
        {
            int left;
            int len;
            scanf("%d%d", &left, &len);
            modify(1, left, len, 0);
        }
    }
    cout << cnt << endl;
}