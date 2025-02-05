#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105, MOD = 20091119;
char s[MAXN];
int a[MAXN], len;
int dp[2][MAXN];
int temp[MAXN], total;
int check()
{
    for (int i = total, j = (len >> 1) + (len & 1); i && j; i--, j--)
    { //+(len&1)判断奇/偶回文数。
        if (temp[i] > a[j])
            return 0;
        if (temp[i] < a[j])
            return 1;
    }
    return 1;
}
int dfs(bool lim, int pos)
{ // lim为1时代表前面高位的都和原数一样，pos为当前下标。
    if (pos == (len >> 1))
    { // 枚举到一半。
        if (!lim)
            return 1;   // 如果lim为0，后面可以随便取，返回1。
        return check(); // 否则判断一下是否超出原数，仅会判断1次。
    }
    if (~dp[lim][pos])
        return dp[lim][pos];
    int res = 0;
    for (int i = 0; i <= 9; i++)
    {
        if (pos == len && !i)
            continue; // 最高位必不等0。
        if (lim && i > a[pos])
            break;         // 超出原数就终止循环。
        temp[++total] = i; // 存下回文数的一半。
        res = (res + dfs(lim && i == a[pos], pos - 1)) % MOD;
        total--;
    }
    return dp[lim][pos] = res;
}
int solve()
{
    for (int i = 1; i <= len; i++)
        a[i] = s[len - i + 1] - 48; // 转成数字，a[1]为个位。
    int res = 0;
    for (int i = len - 1; i; i--)
    {
        int res2 = 9; // 避免前导零。
        for (int j = i - 1; j > (i >> 1); j--)
            res2 = (res2 * 10) % MOD;
        res = (res + res2) % MOD;
    }
    // 提前计算不足n位的数的回文数个数。
    memset(dp, -1, sizeof(dp));
    res = (res + dfs(1, len)) % MOD;
    return res;
}
int main()
{
    scanf("%s", s + 1);
    len = strlen(s + 1);
    printf("%d", solve());
    return 0;
}
