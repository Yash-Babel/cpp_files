#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i, a, b) for (int i = a; i < b; i++)
const int mod = 1000000007;

const int INF = 1e9 + 10;
const int N = 1e5 + 1;
vector<vector<bool>> visited(N);
vector<vector<int>> level(N);

vector<pair<int, int>> movements = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValid(int x, int y)
{
    return (x > 0 && x < N && y > 0 && y < N);
}

void reset()
{
    f(i, 0, N)
    {
        f(j, 0, N)
        {
            visited[i][j] = 0;
            level[i][j] = INF;
        }
    }
}

void bfs(int sx, int sy)
{
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
    }
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
    int sx, sy, dx, dy;
    cin >> sx >> sy >> dx >> dy;
}