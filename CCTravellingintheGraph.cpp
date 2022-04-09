#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const int mod = 1000000007;

vector<vector<pair<int, int>>> graph;
int n, m;

int dijkstra(int source, int destination)
{
    vector<int> arrival(n + 1, 1e9);
    vector<int> departure(n + 1, 1e9);
    vector<int> visited(n + 1, 0);
    arrival[0] = 0;
    set<pair<int, int>> s;
    s.insert({0, source});
    while (!s.empty())
    {
        auto exploringPair = (*s.begin());
        s.erase(exploringPair);
        visited[exploringPair.second] = 1;
        departure[exploringPair.second] = arrival[exploringPair.second];
        for (auto unexploredPair : graph[exploringPair.second])
        {
            if (arrival[unexploredPair.first] > departure[exploringPair.second] + unexploredPair.second)
            {
                s.erase({arrival[unexploredPair.first], unexploredPair.first});
                arrival[unexploredPair.first] = departure[exploringPair.second] + unexploredPair.second;
                s.insert({arrival[unexploredPair.first], unexploredPair.first});
            }
        }
    }
    return arrival[destination];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int u, v;
        cin >> n >> m;
        graph.resize(n);
        vector<int> present(n, 0);
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            --u, --v;
            graph[u].push_back({v, 0});
            graph[v].push_back({u, 0});
            if (abs(v - u) == 1)
            {
                present[min(u, v)] = 1;
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (present[i] == 0)
            {
                graph[i].push_back({i + 1, 1});
                graph[i + 1].push_back({i, 1});
            }
        }
        int answer = dijkstra(0, n - 1);
        cout << answer << "\n";
        graph.clear();
    }
    return 0;
}