#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define all(v) v.abegin(), v.end()
typedef long long ll;
void solve()
{
    // -1 3 -2 5 3 -5 2 2 
    // -1 -1 -1;
    // -1 3 -2
  int n;
  cin >> n;
  ll ans = -1e18, sum = 0;
  for(int i = 0; i < n; ++i)
  {
    int x;
    cin >> x;
    sum += x;
    ans = max(ans, sum);
    sum = max(sum, 0LL);
  }
  cout << ans << '\n';
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  size_t t = 1;
//   cin >> t;
  while (t--)
    solve();
}