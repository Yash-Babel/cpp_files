#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i, a, b) for (int i = a; i < b; i++)
const int mod = 1000000007;

const int INF = 1e9 + 10;
bool visited[8][8];
int level[8][8]{INF};
vector<pair<int, int>> movements = {
    {-1, 2}, {1, 2}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {-2, -1}, {-2, 1}};

bool isValid(int x, int y)
{
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

int getX(string s)
{
    return s[0] - 'a';
}

int getY(string s)
{
    return s[1] - '1';
}

void reset()
{
    f(i, 0, 8)
    {
        f(j, 0, 8)
        {
            visited[i][j] = 0;
            level[i][j] = INF;
        }
    }
}

int bfs(string source, string destination)
{
    int sx = getX(source);
    int sy = getY(source);
    int dx = getX(destination);
    int dy = getY(destination);
    queue<pair<int, int>> qu;
    qu.push({sx, sy});
    visited[sx][sy] = 1;
    level[sx][sy] = 0;
    while (!qu.empty())
    {
        pair<int, int> v = qu.front();
        qu.pop();
        int x = v.first, y = v.second;
        int tmp = level[x][y];
        for (auto movement : movements)
        {
            int childX = x + movement.first, childY = y + movement.second;
            if (visited[childX][childY] || !isValid(childX, childY))
            {
                continue;
            }
            qu.push({childX, childY});
            level[childX][childY] = level[x][y] + 1;
            visited[childX][childY] = 1;
        }
        if (level[dx][dy] != INF)
        {
            break;
        }
    }
    return level[dx][dy];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        reset();
        string s1, s2;
        cin >> s1 >> s2;
        cout << bfs(s1, s2) << '\n';
    }
}
