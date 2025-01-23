#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#define N 2000007
using namespace std;
int n, m;
struct Segment_Tree // 线段树结构体
{
    int Max[N << 2], Min[N << 2];               // 懒标记
    inline int ls(int p) { return p << 1; }     // 左子树
    inline int rs(int p) { return p << 1 | 1; } // 右子树
    void fx(int p, int k)                       // Max标记传递 ，p节点编号，k传递值
    {
        if (Min[p] < k)
            Min[p] = k; // Min比k小，更新Min
        if (Max[p] < k)
            Max[p] = k; // 连Max都比k小，更新MMax
    }
    void fi(int p, int k) // Min标记传递，p节点编号，k传递值
    {
        if (Max[p] > k)
            Max[p] = k; // Max比k要大，缩小Max
        if (Min[p] > k)
            Min[p] = k; // Min都比k大，k更小，值取k
    }
    //    释放懒标记
    void push_down(int p)
    {
        //        更新Max
        fx(ls(p), Max[p]);
        fx(rs(p), Max[p]);
        //        更新Min
        fi(ls(p), Min[p]);
        fi(rs(p), Min[p]);
        //        Max 和 Min 回归初始状态
        Max[p] = 0;
        Min[p] = 0x7fffffff;
    }
    //    		修改区间[nl,nr]	当前节点p,代表区间[l,r] 修改数k	,tag判断是操作add还是操作rem
    void update(int nl, int nr, int p, int l, int r, int k, bool tag)
    {
        cerr << l << ' ' << r << endl;
        //    	在范围内
        if (nl <= l && r <= nr)
        {
            //        	tag==0 代表add操作，更新Max
            if (tag == 0)
                fx(p, k);
            //            否则更新Min
            else
                fi(p, k);
            return;
        }
        int mid = (l + r) >> 1;
        //        释放懒标记
        push_down(p);
        if (nl <= mid)
            update(nl, nr, ls(p), l, mid, k, tag);
        if (nr > mid)
            update(nl, nr, rs(p), mid + 1, r, k, tag);
        //        push_up(p);
    }
    void Query(int p, int l, int r)
    {
        
        //    	依次输出 叶节点的Max和Min是一样的
        if (l == r)
        {
            printf("%d\n", Max[p]);
            return;
        }
        int mid = (l + r) >> 1;
        //        记得先释放懒标记，更新值
        push_down(p);
        //        继续递归
        Query(ls(p), l, mid);
        Query(rs(p), mid + 1, r);
    }
} Tree; // 定义一棵线段树Tree
int main()
{
    scanf("%d%d", &n, &m);
    //    把Min数组全直无穷大
    for (int i = 1; i <= n << 2; ++i)
        Tree.Min[i] = 0x7fffffff;
    for (int i = 1; i <= m; ++i)
    {
        int L, R, h, t; // 修改区间[L,R],修改值h,和操作t
        scanf("%d%d%d%d", &t, &L, &R, &h);
        //        题目从0开始编号，我习惯从一开始，故+1
        Tree.update(L + 1, R + 1, 1, 1, n, h, t - 1);
    }
    //    输出结果
    Tree.Query(1, 1, n);
    return 0;
}