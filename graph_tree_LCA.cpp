#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const int mod = 1000000007;

const int N = 1e5 + 10;
vector<int> graph[N];
int parentOf[N];
void DFS(int currentVertex, int parent = 0)
{
    // cout << "Entering the parent " << currentVertex << "\n";
    for (int child : graph[currentVertex])
    {
        if (child != parent)
        {
            parentOf[child] = currentVertex;
            // cout << "Entering the child " << vertex << "\n";
            DFS(child, currentVertex);
            // cout << "Exiting the child " << vertex << "\n";
        }
    }
    // cout << "Exiting the parent " << currentVertex << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int V;
    cin >> V;
    for (int i = 0; i < V - 1; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    DFS(1);
    // for (int i = 1; i <= V; i++)
    // {
    //     cout << parentOf[i] << '\n';
    // }
    int n1, n2, answer; // to find LCA of
    cin >> n1 >> n2;
    vector<int> n1Path, n2Path;
    while (n1 != 1)
    {
        n1Path.push_back(n1);
        n1 = parentOf[n1];
    }
    n1Path.push_back(1);
    while (n2 != 1)
    {
        n2Path.push_back(n2);
        n2 = parentOf[n2];
    }
    n2Path.push_back(1);
    int i = n1Path.size() - 2, j = n2Path.size() - 2;
    while (true)
    {
        if (n1Path[i] != n2Path[j])
        {
            answer = n1Path[i + 1];
            break;
        }
        i--, j--;
    }
    cout << answer;
}