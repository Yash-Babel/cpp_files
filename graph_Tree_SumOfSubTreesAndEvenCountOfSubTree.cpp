#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const int mod = 1000000007;
/*give a tree input and then give a number representing of query to be asked then input queries
  and this program will return sum of subtree and number of even numbers in the sub tree of the asked query.
*/
const int N = 1e5 + 10;
vector<int> graph[N];
int sumOfSubTree[N]{0};
int evenCountOfSubTree[N]{0};

// Pre-computing the sum of subtrees of all vertices in the tree
// and then asking quries to print the required sum.

void DFS(int currentVertex, int parent = 0)
{
    // cout << "Entering the parent " << currentVertex << "\n";
    for (int child : graph[currentVertex])
    {
        if (child != parent)
        {
            // cout << "Entering the child " << vertex << "\n";
            DFS(child, currentVertex);
            // cout << "Exiting the child " << vertex << "\n";
            sumOfSubTree[currentVertex] += sumOfSubTree[child];
            evenCountOfSubTree[currentVertex] += evenCountOfSubTree[child];
        }
    }
    sumOfSubTree[currentVertex] += currentVertex;
    if (!(currentVertex % 2))
    {
        evenCountOfSubTree[currentVertex] += 1;
    }
    // cout << "Exiting the parent " << currentVertex << "\n";
}

int main()
{
    int V, E, numberOfQueries, query;
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    DFS(1);

    for (int i = 1; i < V + 1; i++)
    {
        cout << "Sum of subtree of " << i << " is : " << sumOfSubTree[i]
             << " and even numbers is : " << evenCountOfSubTree[i] << "\n";
    }

    cin >> numberOfQueries;
    for (int i = 1; i < V + 1; i++)
    {
        cin >> query;
        cout << sumOfSubTree[query] << " " << evenCountOfSubTree[query] << "\n";
    }
}