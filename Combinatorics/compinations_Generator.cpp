int cnt = 0;
//finding the compinations 
vector<int> compin;
void comp(int n, int m, int i = 0, int last = 0)
{
    if (i == m)
    {
        ++cnt;
        for (auto &it : compin)
            cout << it << ' ';
        cout << '\n';
        return;
    }

    for (int j = last + 1; j <= n; ++j)
    {
        compin.push_back(j);
        comp(n, m, i + 1, j);
        compin.pop_back();
    }
}