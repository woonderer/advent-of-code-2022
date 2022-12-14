#include <bits/stdc++.h>
using namespace std;

pair <int, int> rope[10];
set <pair <int, int>> s;

bool is_adj(int n)
{
    return abs(rope[n].first - rope[n - 1].first) <= 1 && abs(rope[n].second - rope[n - 1].second) <= 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.in", "r", stdin);

    string line;
    while (getline(cin, line))
    {
        char dir;
        int m;
        sscanf(line.c_str(), "%c %d", &dir, &m);

        while (m--)
        {
            if (dir == 'R') rope[0].second++;
            else if (dir == 'L') rope[0].second--;
            else if (dir == 'U') rope[0].first--;
            else rope[0].first++;

            for (int i = 1; i <= 9; i++)
            {
                if (!is_adj(i))
                {
                    if (rope[i - 1].second > rope[i].second) rope[i].second++;
                    else if (rope[i - 1].second < rope[i].second) rope[i].second--;

                    if (rope[i - 1].first > rope[i].first) rope[i].first++;
                    else if (rope[i - 1].first < rope[i].first) rope[i].first--;
                }
            }
            s.insert(rope[9]);
        }
    }
    cout << s.size();
}