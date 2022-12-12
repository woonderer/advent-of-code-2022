#include <bits/stdc++.h>
using namespace std;

int g[200][200];
int ans[200][200];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.in", "r", stdin);

    string line;
    pair <int, int> s, e;
    for (int i = 1; i <= 41; i++)
    {
        getline(cin, line);
        for (int j = 0; j < line.size(); j++)
        {
            g[i][j + 1] = line[j];
            if (line[j] == 'S')
            {
                s = {i, j + 1};
                g[i][j + 1] = 'a';
            }
            else if (line[j] == 'E')
            {
                e = {i, j + 1};
                g[i][j + 1] = 'z';
            }
        }
    }

    queue <pair <pair <int, int>, int>> q;
    q.push({s, 0});
    while (!q.empty())
    {
        auto cur = q.front().first;
        auto ile = q.front().second;
        q.pop();
        if (ans[cur.first][cur.second] != 0) continue;
        ans[cur.first][cur.second] = ile;

        if (cur.first - 1 >= 1 && ans[cur.first - 1][cur.second] == 0 && g[cur.first - 1][cur.second] <= g[cur.first][cur.second] + 1) 
                q.push({{cur.first - 1, cur.second}, ile + 1});
        if (cur.first + 1 <= 159 && ans[cur.first + 1][cur.second] == 0 && g[cur.first + 1][cur.second] <= g[cur.first][cur.second] + 1) 
                q.push({{cur.first + 1, cur.second}, ile + 1});
        if (cur.second - 1 >= 1 && ans[cur.first][cur.second - 1] == 0 && g[cur.first][cur.second - 1] <= g[cur.first][cur.second] + 1) 
                q.push({{cur.first, cur.second - 1}, ile + 1});
        if (cur.second + 1 <= 159 && ans[cur.first][cur.second + 1] == 0 && g[cur.first][cur.second + 1] <= g[cur.first][cur.second] + 1) 
                q.push({{cur.first, cur.second + 1}, ile + 1});
    }
    cout << ans[e.first][e.second] << '\n';
}
