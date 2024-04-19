#include <bits/stdc++.h>
#include <math.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> visited;
int cnt = 0;
bool isSyclic = 0;
void dfs(int node, int prev = 0)
{
    visited[node] = 1;
    ++cnt;
    for (auto it : adj[node])
    {
        if (!visited[it])
            dfs(it, node);
        else
        {
            if (it != prev)
                isSyclic = 1;
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    visited.resize(n + 1, 0);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int res = 0;
    // connected components
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            dfs(i);
            if ((cnt & 1) && isSyclic)
            {
                ++res;
            }
            isSyclic = 0;
            cnt = 0;
        }
    }
    cout << (((n - res) & 1) ? ++res : res) << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}