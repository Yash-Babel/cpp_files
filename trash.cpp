#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i, a, b) for (int i = a; i < b; i++)
const int mod = 1000000007;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int n, m, k, q;
    cin >> n >> m;
    vector<set<int>> vs(n + 1, {0});
    for (int i = 0; i < m; i++)
    {
        cin >> k;
        int arr[k];
        for (int i = 0; i < k; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < k; i++)
        {
            for (int j = i + 1; j < k; j++)
            {
                vs[arr[i]].insert(arr[j]);
                vs[arr[j]].insert(arr[i]);
            }
        }
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        if (vs[a].count(b))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}