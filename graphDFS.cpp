#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const int mod = 1000000007;

const int N = 1e5 + 10;
vector<int> graph[N];
bool visited[N];
void DFS(int currentVertex)
{
    visited[currentVertex] = true;
    cout << "Entering the parent " << currentVertex << "\n";
    for (int vertex : graph[currentVertex])
    {
        if (!visited[vertex])
        {
            cout << "Entering the child " << vertex << "\n";
            DFS(vertex);
            cout << "Exiting the child " << vertex << "\n";
        }
    }
    cout << "Exiting the parent " << currentVertex << "\n";
}
int main()
{
    int V, E;
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    DFS(1);
}
