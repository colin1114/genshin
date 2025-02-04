#include <bits/stdc++.h>
using namespace std;


struct TwoSat
{
    int n;
    vector<vector<int>> g, gr;
    vector<int> order, comp, assignment;
    vector<bool> used;
    TwoSat(int vars) : n(vars)
    {
        g.resize(2 * n);
        gr.resize(2 * n);
        assignment.assign(n, 0);
    }
    int neg(int x) { return x ^ 1; }

    void add_edge(int u, int v)
    {
        g[u].push_back(v);
        gr[v].push_back(u);
    }
    void add_clause(int x, int y)
    {
        add_edge(neg(x), y);
        add_edge(neg(y), x);
    }

    void dfs1(int v)
    {
        used[v] = true;
        for (int nx : g[v])
            if (!used[nx])
                dfs1(nx);
        order.push_back(v);
    }

    void dfs2(int v, int cl)
    {
        comp[v] = cl;
        for (int nx : gr[v])
            if (comp[nx] == -1)
                dfs2(nx, cl);
    }

    bool solve()
    {
        int nodes = 2 * n;
        used.assign(nodes, false);
        order.clear();
        for (int i = 0; i < nodes; i++)
            if (!used[i])
                dfs1(i);
        comp.assign(nodes, -1);
        int idx = 0;
        for (int i = nodes - 1; i >= 0; i--)
        {
            int v = order[i];
            if (comp[v] == -1)
                dfs2(v, idx++);
        }
        for (int i = 0; i < n; i++)
        {
            if (comp[2 * i] == comp[2 * i + 1])
                return false;
            assignment[i] = (comp[2 * i] < comp[2 * i + 1]);
        }
        return true;
    }
};


int N;
vector<vector<int>> A; 
unordered_map<int, int> freqMap;

unordered_map<int, vector<int>> freqCandidates;

unordered_map<int, vector<int>> candMapping;

void initFreqCandidates(int n)
{
    freqCandidates.clear();
    for (int s = 2; s <= 2 * n; s++)
    {
        int f;
        if (s <= n + 1)
            f = s - 1;
        else
            f = 2 * n - s + 1;
        freqCandidates[f].push_back(s);
    }
    for (auto &p : freqCandidates)
        sort(p.second.begin(), p.second.end());
}
void initCandMapping()
{
    candMapping.clear();
    for (auto &p : freqMap)
    {
        int v = p.first, cnt = p.second;
        candMapping[v] = freqCandidates[cnt];
    }
}
bool inCand(int v, int candidateVal)
{
    for (int x : candMapping[v])
        if (x == candidateVal)
            return true;
    return false;
}

vector<vector<int>> allowedMask;
void computeAllowedMask(int fixedX1)
{
    allowedMask.assign(N + 1, vector<int>(N + 1, 0));
    for (int i = 2; i <= N; i++)
    {
        int rowVal = A[i - 1][0];
        auto &rowCand = candMapping[rowVal];
        int R0 = rowCand[0];
        int R1 = (rowCand.size() == 2 ? rowCand[1] : -100);
        for (int j = 2; j <= N; j++)
        {
            int colVal = A[0][j - 1]; // A[1,j]
            auto &colCand = candMapping[colVal];
            int C0 = colCand[0];
            int C1 = (colCand.size() == 2 ? colCand[1] : -100);

            int mask = 0;
            int val00 = R0 + C0 - fixedX1;
            if (inCand(A[i - 1][j - 1], val00))
                mask |= 1;
            if (colCand.size() == 2)
            {
                int val01 = R0 + C1 - fixedX1;
                if (inCand(A[i - 1][j - 1], val01))
                    mask |= 2;
            }
            if (rowCand.size() == 2)
            {
                int val10 = R1 + C0 - fixedX1;
                if (inCand(A[i - 1][j - 1], val10))
                    mask |= 4;
            }
            if (rowCand.size() == 2 && colCand.size() == 2)
            {
                int val11 = R1 + C1 - fixedX1;
                if (inCand(A[i - 1][j - 1], val11))
                    mask |= 8;
            }
            allowedMask[i][j] = mask;
        }
    }
}

struct Clause
{
    int x, y; 
};

vector<Clause> clauses;

void addClause(vector<Clause> &clauses, int x, int y)
{
    clauses.push_back({x, y});
}

void addCellClauses(int i, int j, int N, vector<Clause> &clauses)
{
    int mask = allowedMask[i][j];
    for (int a = 0; a < 2; a++)
    {
        for (int b = 0; b < 2; b++)
        {
            int bit = a * 2 + b;
            if (mask & (1 << bit))
                continue;
            int rowVar = i - 2;
            int colVar = (N - 1) + (j - 2);
            int litRow = rowVar * 2 + (a ^ 1); 
            int litCol = colVar * 2 + (b ^ 1); 
            addClause(clauses, litRow, litCol);
        }
    }
}


bool solve2SAT(int varCount, const vector<Clause> &baseClauses, const vector<int> &extraLits, vector<int> &sol)
{
    TwoSat ts(varCount);
    for (auto &cl : baseClauses)
        ts.add_clause(cl.x, cl.y);
    for (int lit : extraLits)
        ts.add_clause(lit, lit);
    bool sat = ts.solve();
    if (sat)
        sol = ts.assignment;
    return sat;
}

vector<int> lexAssign;

bool computeLexAssignment(int varCount, const vector<Clause> &baseClauses, vector<int> &bestAssign)
{
    int total = varCount;
    vector<int> orderIndices;
    int rCount = N - 1, cCount = N - 1;
    for (int j = 2; j <= N; j++)
    {
        orderIndices.push_back((N - 1) + (j - 2));
    }
    for (int i = 2; i <= N; i++)
    {
        orderIndices.push_back(i - 2);
    }

    vector<int> extra;
    lexAssign.assign(varCount, -1);
    vector<int> dummy;
    for (int idx : orderIndices)
    {
        int falseLit = idx * 2 + 0;
        vector<int> trialExtra = extra;
        trialExtra.push_back(falseLit);
        vector<int> sol;
        if (solve2SAT(varCount, baseClauses, trialExtra, sol))
        {
            extra.push_back(falseLit);
            lexAssign[idx] = 0;
        }
        else
        {
            int trueLit = idx * 2 + 1;
            trialExtra = extra;
            trialExtra.push_back(trueLit);
            if (solve2SAT(varCount, baseClauses, trialExtra, sol))
            {
                extra.push_back(trueLit);
                lexAssign[idx] = 1;
            }
            else
            {
                return false;
            }
        }
    }
    vector<int> finalSol;
    if (!solve2SAT(varCount, baseClauses, extra, finalSol))
        return false;
    lexAssign = finalSol;
    bestAssign = lexAssign;
    return true;
}

bool computeRC(vector<int> &solRows, vector<int> &solCols, int fixedX1, int fixedY1, vector<int> &rOut, vector<int> &cOut)
{
    vector<int> Xvals(N + 1), Yvals(N + 1);
    Xvals[1] = fixedX1;
    Yvals[1] = fixedY1;
    for (int i = 2; i <= N; i++)
    {
        int rowVal = A[i - 1][0];
        auto &cand = candMapping[rowVal];
        int decision = (cand.size() == 2 ? lexAssign[i - 2] : 0);
        Xvals[i] = cand[decision];
    }
    for (int j = 2; j <= N; j++)
    {
        int colVal = A[0][j - 1];
        auto &cand = candMapping[colVal];
        int decision = (cand.size() == 2 ? lexAssign[(N - 1) + (j - 2)] : 0);
        Yvals[j] = cand[decision];
    }
    for (int i = 2; i <= N; i++)
    {
        for (int j = 2; j <= N; j++)
        {
            int computed = Xvals[i] + Yvals[j] - fixedX1;
            if (!inCand(A[i - 1][j - 1], computed))
                return false;
        }
    }
    int minR = INT_MAX, maxR = INT_MIN;
    vector<int> rprime(N + 1);
    for (int i = 1; i <= N; i++)
    {
        rprime[i] = Xvals[i] - Xvals[1];
        minR = min(minR, rprime[i]);
        maxR = max(maxR, rprime[i]);
    }
    if (maxR - minR != N - 1)
        return false;
    int t = 1 - minR;
    vector<int> rArr(N + 1), cArr(N + 1);
    for (int i = 1; i <= N; i++)
        rArr[i] = rprime[i] + t;
    for (int j = 1; j <= N; j++)
        cArr[j] = Yvals[j] - t;
    vector<bool> usedR(N + 1, false), usedC(N + 1, false);
    for (int i = 1; i <= N; i++)
    {
        if (rArr[i] < 1 || rArr[i] > N || usedR[rArr[i]])
            return false;
        usedR[rArr[i]] = true;
    }
    for (int j = 1; j <= N; j++)
    {
        if (cArr[j] < 1 || cArr[j] > N || usedC[cArr[j]])
            return false;
        usedC[cArr[j]] = true;
    }
    rOut = rArr;
    cOut = cArr;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
            freqMap[A[i][j]]++;
        }
    }
    initFreqCandidates(N);
    initCandMapping();
    int fixedX1 = candMapping[A[0][0]][0];
    int fixedY1 = fixedX1; 
    computeAllowedMask(fixedX1);
    clauses.clear();
    for (int i = 2; i <= N; i++)
    {
        for (int j = 2; j <= N; j++)
        {
            addCellClauses(i, j, N, clauses);
        }
    }

    int totVars = 2 * (N - 1); 
    vector<int> bestAssign;
    if (!computeLexAssignment(totVars, clauses, bestAssign))
    {
        cout << -1 << "\n";
        return 0;
    }
    lexAssign = bestAssign;
    vector<int> Xvals(N + 1), Yvals(N + 1);
    Xvals[1] = fixedX1;
    Yvals[1] = fixedY1;
    for (int i = 2; i <= N; i++)
    {
        int rowVal = A[i - 1][0];
        auto &cand = candMapping[rowVal];
        int decision = (cand.size() == 2 ? lexAssign[i - 2] : 0);
        Xvals[i] = cand[decision];
    }
    for (int j = 2; j <= N; j++)
    {
        int colVal = A[0][j - 1];
        auto &cand = candMapping[colVal];
        int decision = (cand.size() == 2 ? lexAssign[(N - 1) + (j - 2)] : 0);
        Yvals[j] = cand[decision];
    }
    bool ok = true;
    for (int i = 2; i <= N && ok; i++)
    {
        for (int j = 2; j <= N && ok; j++)
        {
            int computed = Xvals[i] + Yvals[j] - fixedX1;
            if (!inCand(A[i - 1][j - 1], computed))
                ok = false;
        }
    }
    if (!ok)
    {
        cout << -1 << "\n";
        return 0;
    }
    vector<int> rArr, cArr;
    if (!computeRC(lexAssign, lexAssign, fixedX1, fixedY1, rArr, cArr))
    {
        cout << -1 << "\n";
        return 0;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout << rArr[i] + cArr[j] << (j == N ? "\n" : " ");
        }
    }
    return 0;
}
