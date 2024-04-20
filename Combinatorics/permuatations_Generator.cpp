
// finding the permuatations of array
int perm_cnt = 0;
vector<int> num = {12, 23, 31, 24};
//          vis = {0, 0, 0, 0};
vector<bool> vis(4);
vector<int> permuation;
void perm(int i = 0)
{
    if (i == num.size())
    {
        for (auto &it : permuation)
            cout << it << ' ';
        cout << '\n';
        ++perm_cnt;
        return;
    }
    for (int j = 0; j < num.size(); ++j)
    {
        if (vis[j])
            continue;
        vis[j] = 1;
        permuation.push_back(num[j]);
        perm(i + 1);
        vis[j] = 0;
        permuation.pop_back();
    }
}