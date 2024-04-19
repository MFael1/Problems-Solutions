#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define all(arr) arr.begin(), arr.end();
vector<vector<int>> v;
vector<char> vis;
bool iscyclic = 0;
string ans = "";
void dfs(int node)
{
  vis[node] = '1';
  for (auto it : v[node])
  {
    if (vis[it] == '1')
    {
      iscyclic = 1;
      return;
    }
    if (vis[it] == '0')
    {
      dfs(it);
    }
  }
  vis[node] = '2';
  ans += (char)(node + 65);
}
void solve()
{
  v.resize(5);
  vis.resize(5, '0');
  for (int i = 0; i < 5; ++i)
  {
    string s;
    cin >> s;
    int lhs = s[0] - 65, rhs = s[2] - 65;
    char sign = s[1];
    if (sign == '>')
    {
      v[lhs].push_back(rhs);
    }
    else
    {
      v[rhs].push_back(lhs);
    }
  }
  // connected component
  for (int i = 0; i < 5; ++i)
  {
    if (vis[i] == '0')
    {
      dfs(i);
    }
  }
  if (iscyclic)
  {
    cout << "impossible\n";
  }
  else
  {
    cout << ans << '\n';
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  size_t t = 1;
  // cin >> t;
  while (t--)
    solve();
}