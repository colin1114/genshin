#include <bits/stdc++.h>
using namespace std;

// 使用 64 位无符号整数做滚动哈希
typedef unsigned long long ull;
const ull BASE = 131ULL;

// 计算数组 arr 的前缀哈希，arr 元素加了一个常数偏移以避免 0 的影响
vector<ull> computeHash(const vector<int> &arr)
{
    int n = arr.size();
    vector<ull> H(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        H[i + 1] = H[i] * BASE + (ull)(arr[i] + 137);
    }
    return H;
}

// 计算幂数组
vector<ull> computePowers(int len)
{
    vector<ull> powVec(len + 1, 1);
    for (int i = 1; i <= len; i++)
    {
        powVec[i] = powVec[i - 1] * BASE;
    }
    return powVec;
}

// 得到子区间 [l, r]（包含两端）的哈希值
ull getHash(const vector<ull> &H, const vector<ull> &powVec, int l, int r)
{
    return H[r + 1] - H[l] * powVec[r - l + 1];
}

// 结构体存储一行数据及预处理信息
struct RowData
{
    vector<int> A, B;
    vector<int> valid;    // 所有满足 a[0..m-p-1] == B[p..m-1] 的 p
    vector<ull> hashB;    // B 的前缀哈希
    vector<ull> revHashA; // A 反序后（即构成 reverse(A) ）的前缀哈希
};

// 主函数
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<RowData> rows(n);
        // 读入所有行的 A 数组
        for (int i = 0; i < n; i++)
        {
            rows[i].A.resize(m);
            for (int j = 0; j < m; j++)
            {
                cin >> rows[i].A[j];
            }
        }
        // 读入所有行的 B 数组
        for (int i = 0; i < n; i++)
        {
            rows[i].B.resize(m);
            for (int j = 0; j < m; j++)
            {
                cin >> rows[i].B[j];
            }
        }

        // 对本测试例，预先计算一次 powVec（最大 m 不超过 3e5，总元素数不超过 3e5）
        vector<ull> powVec = computePowers(m + 5);

        // 对每一行预处理 valid 集合、B 的前缀哈希以及 A 的反序哈希
        for (int i = 0; i < n; i++)
        {
            // 计算 A 和 B 的前缀哈希
            vector<ull> hashA = computeHash(rows[i].A);
            vector<ull> hashB = computeHash(rows[i].B);
            rows[i].hashB = hashB;
            // 计算 valid：遍历 p=0..m，令 L = m-p，
            // 检查 a[0..L-1] 与 B[p..m-1] 是否相等
            for (int p = 0; p <= m; p++)
            {
                int L = m - p;
                if (L == 0)
                {
                    rows[i].valid.push_back(p);
                }
                else
                {
                    ull ha = hashA[L];                         // a[0..L-1] 的哈希
                    ull hb = getHash(hashB, powVec, p, m - 1); // B[p..m-1] 的哈希
                    if (ha == hb)
                        rows[i].valid.push_back(p);
                }
            }
            // 对 A 反序构造 revA, 则 revA[0..p-1] 就对应 reverse(a[m-p..m-1])
            vector<int> revA(m);
            for (int j = 0; j < m; j++)
            {
                revA[j] = rows[i].A[m - 1 - j];
            }
            rows[i].revHashA = computeHash(revA);
        }

        // DP：dp[i] 表示第 i 行（0-index）可能得到的“位移数”集合，
        // 即所有选取 p_i ∈ 𝒱_i（合法的位移数），并且满足前面各行传递条件的 p_i。
        // 转移时：若第 i 行存在某个 p (p>0时需满足：rows[i+1].B[0..p-1] == reverse(rows[i].A[m-p..m-1]))
        // 我们令 T = min { p ∈ dp[i] 能过渡 }，则 dp[i+1] = { q ∈ 𝒱_{i+1} : q ≥ T }.

        // 初始 dp[0] 为第 1 行的所有合法 p
        vector<int> dp = rows[0].valid; // 已经递增
        bool possible = true;

        // 从第 1 行向下转移
        for (int i = 0; i < n - 1; i++)
        {
            // 对 dp[i] 中的每个状态 p，检查链条件（条件2）是否成立
            int T = m + 1; // 取所有通过条件的 p 的最小值
            for (int p : dp)
            {
                bool chainOk = false;
                if (p == 0)
                {
                    chainOk = true; // 空串，总成立
                }
                else
                {
                    // 利用 precomputed revHashA, rows[i].revHashA 表示 reverse(A) 的前缀哈希
                    // 计算 rows[i+1].B[0..p-1] 的哈希：
                    ull hb = getHash(rows[i + 1].hashB, powVec, 0, p - 1);
                    // 计算 rows[i].revHashA[0..p-1] 的哈希：
                    ull hr = getHash(rows[i].revHashA, powVec, 0, p - 1);
                    if (hb == hr)
                        chainOk = true;
                }
                if (chainOk)
                {
                    T = min(T, p);
                }
            }
            if (T == m + 1)
            { // 若没有任何 p 能传递，则无解
                possible = false;
                break;
            }
            // dp[i+1] = { q in rows[i+1].valid with q >= T }.
            vector<int> newDp;
            auto &valNext = rows[i + 1].valid;
            auto it = lower_bound(valNext.begin(), valNext.end(), T);
            for (; it != valNext.end(); it++)
            {
                newDp.push_back(*it);
            }
            if (newDp.empty())
            {
                possible = false;
                break;
            }
            dp = move(newDp);
        }

        if (!possible)
        {
            // 按题意，通常可变换；若无解输出 -1
            cout << -1 << "\n";
        }
        else
            {
            int ans = dp[0];
            cout << ans << "\n";
        }
    }
    return 0;
}
