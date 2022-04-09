#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const int mod = 1000000007;

const int N = 1e5 + 10;
vector<int> graph[N];
int arr[N];
set<int> se;
int answer = 0;
void DFS(int currentVertex, int parent = 0)
{
    bool currentVertexErased = false;
    auto it = se.find(arr[currentVertex]);
    if (it != se.end())
    {
        // cout << "removing " << *it << "\n";
        se.erase(arr[currentVertex]);
        currentVertexErased = true;
    }
    // for (auto itt = se.begin(); itt != se.end(); itt++)
    // {
    //     cout << *itt << " ";
    // }
    // cout << "\n";
    // cout << *it << "\n";
    answer = max(answer, *se.begin());
    for (int child : graph[currentVertex])
    {
        if (child != parent)
        {
            DFS(child, currentVertex);
        }
    }
    // cout << *it << "\n";
    if (currentVertexErased)
    {
        // cout << "adding " << *it << "\n";
        se.insert(arr[currentVertex]);
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
    int t;
    cin >> t;
    while (t--)
    {
        int V;
        cin >> V;
        se.insert(0);
        se.insert(V + 1);
        // se.insert(V + 2);
        for (int i = 1; i <= V; i++)
        {
            cin >> arr[i];
            se.insert(i);
        }
        for (int i = 0; i < V - 1; i++)
        {
            int v1, v2;
            cin >> v1 >> v2;
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }
        DFS(1);
        cout << answer << "\n";
        for (int i = 1; i <= V; i++)
        {
            graph[i].clear();
        }
        answer = 0;
        se.clear();
    }
    return 0;
}