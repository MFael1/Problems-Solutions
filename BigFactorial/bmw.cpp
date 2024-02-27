#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
void solve()
{

}

int fact(int a)
{
    if (a == 0 || a == 1)
        return 1;
    return a * fact(a - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     solve();
    // }
    int x = 1775;
    vector<int> v(10000);
    v[0] = 1;
    for (int i = 1; i <= x; ++i)
    {
        for (int j = 0; j < v.size(); ++j)
        {
            v[j] *= i;
        }
        for (int j = 0; j < v.size() - 1; ++j)
        {
            if (v[j] > 9)
            {
                v[j + 1] += v[j] / 10;
                v[j] %= 10;
            }
        }
    }
    reverse(v.begin(), v.end());
    bool flag = 0;
    for (auto it : v)
    {
        if (it != 0)
            flag = 1;
        if (flag)
            cout << it;
    }
    cout << '\n';
}