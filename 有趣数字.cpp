#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
const int L = 105;

string s, l, r;
ll f[L][10][2];
int ln;
ll solve(int p, int x, int flag)
{
    if (p >= ln)
        return 1;
    if (~f[p][x][flag])
        return f[p][x][flag];
    int lim = flag ? (s[p] - '0') : 9;
    f[p][x][flag] = 0;
    for (int i = x; i <= lim; i++)
        (f[p][x][flag] += solve(p + 1, i, flag && (i == lim))) %= mod;
    return f[p][x][flag];
}

int main()
{
    cin >> l >> r, s = r, ln = s.size();
    memset(f, -1, sizeof(f));
    ll ans = solve(0, 0, 1);
    memset(f, -1, sizeof(f));
    s = l, ln = s.size(), ans -= solve(0, 0, 1) - 1;
    for (int i = 0; i < s.size() - 1; i++)
        if (s[i] > s[i + 1])
        {
            ans--;
            break;
        }
    ans = (ans % mod + mod) % mod;
    cout << ans << endl;
    return 0;
}

/*
# [ROIR 2016] 有趣数字 (Day 2)

## 题目背景

翻译自 [ROIR 2016 D2T3](https://neerc.ifmo.ru/school/archive/2015-2016/ru-olymp-regional-2016-day2.pdf)。

## 题目描述

如果一个整数的各个数位按非递减顺序排列，我们称这个数是“有趣的”。例如，$1145,2333,1377777$ 都是“有趣的”。

给定 $L,R$，求出 $[L,R]$ 中有趣的数字的个数，对 $10^9+7$ 取模。

## 输入格式

输入两行，每行一个数，分别是 $L$ 和 $R$。保证 $1 \leq L \leq R \leq 10^{100}$。

## 输出格式

输出一个数，表示答案。

## 样例 #1

### 样例输入 #1

```
1 100
```

### 样例输出 #1

```
54
```

## 提示

| 子任务 | 是否捆绑 | 分值 | 特殊性质 |
| :----------: | :----------: | :----------: | :----------: |
| $1$ | 是 | $21$ | $L = 1$，$R \leq 1000$ |
| $2$ | 否 | $22$ | $1 \leq L \leq R \leq 10^{18}$ |
| $3$ | 否 | $24$ | $L = 1$，$R = 10^k$，其中 $2 \leq k \leq 100$ |
| $4$ | 否 | $33$ | $1 \leq L \leq R \leq 10^{100}$ |
*/