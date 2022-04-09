#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i, a, b) for (int i = a; i < b; i++)
const int mod = 1000000007;

const int N = 1e5 + 10;
vector<int> graph[N];
bool visited[N];
int level[N];

void BFS(int source)
{
    level[source] = 0;
    queue<int> to_be_checked;
    to_be_checked.push(source);
    visited[source] = 1;
    int vertex;
    while (!to_be_checked.empty())
    {
        vertex = to_be_checked.front();
        to_be_checked.pop();
        for (int child : graph[vertex])
        {
            if (!visited[child])
            {
                level[child] = level[vertex] + 1;
                // cout << "entering " << child << '\n';
                visited[child] = 1;
                to_be_checked.push(child);
            }
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
    int V, E;
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    BFS(1);
    f(i, 1, V + 1)
    {
        cout << "level of " << i << " = " << level[i] << '\n';
    }
}