#include <bits/stdc++.h>
using namespace std;
#define lli long long int

/*
No need of graph here in this ques. Used v1 and v2 to just take input.
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int n, q, answer = 0, x;
    lli v;
    char ch;
    cin >> n >> q;
    int value[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> value[i];
        if (value[i] == 0)
        {
            answer++;
        }
    }
    for (int i = 0; i < q; i++)
    {
        cin >> ch;
        if (ch == 'U')
        {
            cin >> x >> v;
            if (value[x] == 0)
                answer--;
            value[x] += v;
            if (value[x] == 0)
                answer++;
        }
        else
        {
            cin >> x;
            cout << answer << "\n";
        }
    }
    return 0;
}