#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const int mod = 1000000007;

const int N = 1e5 + 10;
vector<int> graph[N];
bool visited[N];

stack<int> lastVisited;
int numberOfCycles = 0;
void DFS(int currentVertex)
{
    visited[currentVertex] = true;
    // cout << "Entering the parent " << currentVertex << "\n";
    for (int vertex : graph[currentVertex])
    {
        if (!visited[vertex])
        {
            // cout << "Entering the child " << vertex << "\n";
            DFS(vertex);
            // cout << "Exiting the child " << vertex << "\n";
        }
    }
    // cout << "Exiting the parent " << currentVertex << "\n";
}

void DFStoCountCycles(int currentVertex)
{
    visited[currentVertex] = true;
    // cout << "Entering the parent " << currentVertex << "\n";
    for (int vertex : graph[currentVertex])
    {
        if (visited[vertex] && !lastVisited.empty() && vertex != lastVisited.top())
        {
            numberOfCycles++;
        }
        else if (!visited[vertex])
        {
            lastVisited.push(currentVertex);
            // cout << "Entering the child " << vertex << "\n";
            DFStoCountCycles(vertex);
            // cout << "Exiting the child " << vertex << "\n";
            lastVisited.pop();
        }
    }
    // cout << "Exiting the parent " << currentVertex << "\n";
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

    // int numberOfConnectedComponents = 0;
    // for (int i = 1; i < V + 1; i++)
    // {
    //     if (!visited[i])
    //     {
    //         DFS(i);
    //         numberOfConnectedComponents++;
    //     }
    // }
    // cout << numberOfConnectedComponents;

    for (int i = 1; i < V + 1; i++)
    {
        if (!visited[i])
        {
            DFStoCountCycles(i);
        }
    }
    cout << numberOfCycles;
    return 0;
}
