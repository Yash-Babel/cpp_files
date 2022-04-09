#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i, a, b) for (int i = a; i < b; i++)
const int mod = 1000000007;
const int N = 2 * 1e5 + 10;
vector<int> graph[N];
lli weights[N];
bool visited[N]{0};
lli answer[N]{0};
void dijkstra(int vertex)
{
    visited[vertex] = 1;
    for (int child : graph[vertex])
    {
        if (!visited[child] && child > vertex)
        {
            dijkstra(child);
            if (answer[vertex] < answer[child])
            {
                answer[vertex] = answer[child];
            }
        }
    }
    answer[vertex] += weights[vertex];
    // cout << answer[vertex] << " ";
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        lli n, tmp;
        cin >> n;
        f(i, 1, n + 1)
        {
            cin >> tmp;
            weights[i] = tmp;
            // cout << weights[i] << " ";
            if (i + tmp <= n)
            {
                graph[i].push_back(i + tmp);
                graph[i + tmp].push_back(i);
            }
        }
        f(i, 1, n + 1)
        {
            if (!visited[i])
            {
                dijkstra(i);
            }
        }
        int maxi = 0;
        f(i, 1, n + 1)
        {
            if (maxi < answer[i])
            {
                maxi = answer[i];
            }
        }
        cout << maxi << "\n";
        f(i, 1, n + 1)
        {
            graph[i].clear();
            visited[i] = 0;
            answer[i] = 0;
        }
    }
    return 0;
}