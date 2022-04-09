#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const int mod = 1000000007;

const int N = 1e5 + 10;
vector<int> graph[N];

int deptharr[N]{0}, heightarr[N]{0}, depth = -1, height;

void DFS(int currentVertex, int parent = 0)
{
    depth++;
    deptharr[currentVertex] = depth;
    // cout << "Entering the parent " << currentVertex << "\n";
    for (int child : graph[currentVertex])
    {
        if (child != parent)
        {
            height = 0;
            // cout << "Entering the child " << vertex << "\n";
            DFS(child, currentVertex);
            // cout << "Exiting the child " << vertex << "\n";
        }
        if (heightarr[currentVertex] < height)
        {
            heightarr[currentVertex] = height;
        }
    }
    height++;
    depth--;
    // cout << "Exiting the parent " << currentVertex << "\n";
}

int main()
{
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
    for (int i = 1; i <= V; i++)
    {
        cout << "depth of " << i << " is : " << deptharr[i] << " and height is : " << heightarr[i] << "\n";
    }
}
