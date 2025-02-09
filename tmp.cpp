#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
const int inf = 1e9 + 7;
inline int read()
{
    int p = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        p = p * 10 + c - '0';
        c = getchar();
    }
    return f * p;
}
const int maxn = 1503;
struct Edge
{
    int from, to;
} p[maxn << 1];
int n, cnt, head[maxn << 1], val[maxn];
int f[maxn][4];
// 设状态f[x][0],f[x][1],f[x][2]分别表示
// 对于x点,被自己覆盖,被自己的儿子覆盖,被自己的父亲覆盖时
// 满足以x为根的子树所有点都被覆盖的最小代价
inline void add_edge(int x, int y) // 加边
{
    cnt++;
    p[cnt].from = head[x];
    head[x] = cnt;
    p[cnt].to = y;
}
inline void TreeDP(int x, int fa) // 树形DP
{
    f[x][0] = val[x]; // 初值:选择x点
    int sum = 0, must_need_mincost = inf;
    for (int i = head[x]; i; i = p[i].from)
    {
        int y = p[i].to;
        if (y == fa)
            continue;
        TreeDP(y, x);
        int t = min(f[y][0], f[y][1]);
        f[x][0] += min(t, f[y][2]);
        // 自己被自己覆盖:儿子怎么样都行
        f[x][2] += t;
        // 自己被父节点覆盖:儿子必须合法,要么选择儿子,要么是儿子被儿子的儿子覆盖
        // 以下是对f[x][1]的转移，请好好理解
        if (f[y][0] < f[y][1])
            sum++;
        // 如果选择儿子节点更优,选上,计数器sum++，证明选过f[y][0]
        else
            must_need_mincost = min(must_need_mincost, f[y][0] - f[y][1]);
        // 否则记录一个最小的必须支付代价
        // 因为最后要保证x点被y覆盖,必须要找差值最小的,这样才最优
        f[x][1] += t; // 自己被儿子覆盖,那么儿子必须合法
    }
    if (!sum)
        f[x][1] += must_need_mincost;
    // 对于f[x][1]转移:如果一个f[y][0]都没选过,那么必须从差值最小的儿子里面选择一个
}
int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
    {
        int x = read();
        val[x] = read();
        int num = read();
        while (num > 0)
        {
            int y = read();
            add_edge(x, y);
            add_edge(y, x);
            num--;
        }
    }
    TreeDP(1, 0);
    cerr << f[1][0] << ' ' << f[1][1] << ' ' << f[1][2] << endl;
    printf("%d", min(f[1][0], f[1][1]));
    // 由于根节点没有父节点,最后答案就是min(f[1][0],f[1][1])
    // 即1节点被自己覆盖或者被自己的儿子覆盖
    return 0;
}