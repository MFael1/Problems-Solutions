#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define all(v) v.abegin(), v.end()
typedef long long ll;
int n;
vector<vector<char>> v;
vector<vector<bool>> visited;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};


// finding the path with the maximum value
// Example
// 7 8 1
// 7 9 2
// 100 12 15
int mxVal(int x, int y)
{
  if (x >= n || y >= n)
    return 0;
  if (x == n - 1 && y == n - 1)
    return v[x][y];

  int sum1 = mxVal(x, y + 1);
  int sum2 = mxVal(x + 1, y);

  return v[x][y] + max(sum1, sum2);
}

//finding if there a way to reach E from S

bool path(int x1, int y1)
{
  if (x1 >= n || x1 < 0 || y1 >= n || y1 < 0 || v[x1][y1] == 'X' || visited[x1][y1])
    return 0;
  if (v[x1][y1] == 'E')
    return 1;
  visited[x1][y1] = 1;
  for (int i = 0; i < 4; ++i)
  {
    if (path(x1 + dx[i], y1 + dy[i]))
      return true;
  }
  return false;
}

// finding permutation of numbers in n length
int cnt = 0;
void perm(int len, string cur = "")
{
  if (len == 0)
  {
    cout << cur << '\n';
    ++cnt;
    return;
  }
  for (int i = 1; i < 10; ++i)
  {
    perm(len - 1, cur + to_string(i));
  }
}

// vis = {0 0 0 0}
// cur = {0, 1, 2, 3};

// finding the permuatation without repeating
void permet(int i, int n, bool vis[], int cur[])
{
  if (i == n)
  {
    for (int k = 0; k < n; ++k)
    {
      cout << cur[k] << ' ';
    }
    cout << '\n';
    return;
  }

  for (int j = 0; j < n; ++j)
  {
    if (!vis[j])
    {
      cur[j] = i;
      vis[j] = 1;

      permet(i + 1, n, vis, cur);
      vis[j] = 0;
    }
  }
}

void solve()
{
  int x1, y1;
  cin >> n;
  v.resize(n, vector<char>(n));
  visited.resize(n, vector<bool>(n, 0));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
    {
      cin >> v[i][j];
      if (v[i][j] == 'S')
        x1 = i, y1 = j;
    }

  cout << path(x1, y1) << '\n';
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  size_t t = 1;
  // cin >> t;
  int cur[4] = {0, 1, 2, 3};
  bool vis[4] = {0, 0, 0, 0};
  permet(0, 4, vis, cur);
}