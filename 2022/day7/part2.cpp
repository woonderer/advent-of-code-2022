#include <bits/stdc++.h>
using namespace std;

map <string, long long> total_size;
vector <string> cur_dir;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.in", "r", stdin);

    cur_dir.push_back("/");
    string line;
    while (getline(cin, line))
    {
        if (line[0] == '$')
        {
            if (line[2] == 'c')
            {
                if (line[5] == '/') continue;

                string dir;
                for (char c: line)
                {
                    if (c == ' ') dir.clear();
                    else dir.push_back(c);
                }

                if (dir == "..") cur_dir.pop_back();
                else cur_dir.push_back(cur_dir.back() + dir);
            }
        }
        else if (line[0] != 'd')
        {
            string s;
            for (char c: line)
            {
                if (c == ' ') break;
                s.push_back(c);
            }

            for (string d: cur_dir)
                total_size[d] += stoi(s);
        }
    }

    long long ans = 1e9;
    for (auto x: total_size)
        if (30000000 - 70000000 + total_size["/"] <= x.second) ans = min(ans, x.second);

    cout << ans;
}