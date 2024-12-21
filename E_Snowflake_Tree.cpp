#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<vector<int>> adj(N + 1, vector<int>());
    for (int i = 0; i < N - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> degrees(N + 1, 0);
    for (int u = 1; u <= N; ++u)
    {
        degrees[u] = adj[u].size();
    }

    long long global_max = 0;
    for (int u = 1; u <= N; ++u)
    {
        int deg_u = degrees[u];
        if (deg_u == 0)
            continue;
        vector<int> neighbor_degrees;
        for (auto &v : adj[u])
        {
            neighbor_degrees.push_back(degrees[v]);
        }
        sort(neighbor_degrees.begin(), neighbor_degrees.end(), [](const int a, const int b) -> bool
             { return a > b; });
        for (int x = 1; x <= neighbor_degrees.size(); ++x)
        {
            int d_x = neighbor_degrees[x - 1];
            if (d_x >= 2)
            {
                // y = d_x -1 >=1
                long long size_candidate = 1LL + (long long)x * d_x;
                if (size_candidate > global_max)
                {
                    global_max = size_candidate;
                }
            }
            else
                break;
        }
    }
    long long deletions = (long long)N - global_max;

    cout << deletions;
}
