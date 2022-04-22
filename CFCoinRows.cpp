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
    int t = 1;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> m;
        int inputValue[2][m];
        int uSum = 0, lSum = 0, maxLSum = 0;
        f(j, 0, m)
        {
            cin >> inputValue[0][j];
            uSum += inputValue[0][j];
        }
        f(j, 0, m)
        {
            cin >> inputValue[1][j];
            maxLSum += inputValue[1][j];
        }
        maxLSum -= inputValue[1][m - 1];
        int answer = -1;
        int one = 0, two = 0;
        uSum -= inputValue[0][0];
        for (int i = 0; i < m - 1; i++)
        {
            lSum += inputValue[1][i];
            uSum -= inputValue[0][i + 1];
            if (uSum < lSum)
            {
                one = lSum;
                uSum += inputValue[0][i + 1];
                two = uSum;
                break;
            }
        }
        answer = min(one, two);
        cout << answer << '\n';
    }
    return 0;
}