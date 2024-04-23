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
// ..S.X
// XX.X.
// ....X
// X...E.

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
