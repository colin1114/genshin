#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 51, MOD = 1e9 + 7; // 注意能 MOD 的地方都要 MOD，不然会 WA 0pts。
ll pow10[N], dp[N], a[N], count[N], tmpcount[N], ans;
// pow10    : 字面意思，10^n
// dp       : 不考虑前导零的状况
// count    : 统计 0~9 出现次数
// tmpcount : 暂时保存 count，用来减
// ans      : 累加答案
void init() // 预处理 pow10 和 dp。
{
	pow10[0] = 1;
	for (int i = 1; i < 30; i++)
		dp[i] = (dp[i - 1] * 10 % MOD + pow10[i - 1]) % MOD, pow10[i] = 10 * pow10[i - 1] % MOD;
}
void solve(ll x)
{
	int len = 0;
	while (x)
	{
		a[++len] = x % 10;
		x /= 10;
	} // 数位分离
	for (int i = len; i >= 1; i--) // 从高到低遍历
	{
		for (int j = 0; j < 10; j++)
			count[j] += dp[i - 1] * a[i], count[j] %= MOD; // 分割区间
		for (int j = 0; j < a[i]; j++)
			count[j] += pow10[i - 1], count[j] %= MOD; // 加上 10^(n-1)
		ll lastnum = 0;
		for (int j = i - 1; j >= 1; j--)
			lastnum = lastnum * 10 + a[j], lastnum %= MOD; // 求出 A2A3A4...An
		count[a[i]] += lastnum + 1, count[a[i]] %= MOD;
		count[0] -= pow10[i - 1], count[0] = (count[0] + MOD) % MOD; // 减去前导零
	}
}
int main()
{
	init();
	ll l, r, T;
	cin >> T;
	for (int q = 0; q < T; q++)
	{
		ans = 0;
		cin >> l >> r;
		solve(r); // 前缀和思想相减 r 和 l-1。
		for (int i = 0; i < 10; i++)
			(tmpcount[i] = count[i]), count[i] = 0; // 复制 count，记得清零
		solve(l - 1);
		for (int i = 0; i < 10; i++)
			ans = (ans + i * (tmpcount[i] - count[i] + MOD) % MOD) % MOD, count[i] = 0; // 累加答案，记得清零 count。
		cout << ans << '\n';
	}
	return 0;
}