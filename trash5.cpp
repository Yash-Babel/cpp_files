#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i, a, b) for (int i = a; i < b; i++)
const int mod = 1000000007;
void YN(bool possible)
{
    if (possible)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
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
        int n, tmp;
        cin >> n;
        int arr[n + 1]{0};
        arr[0] = 1;
        f(i, 0, n - 1)
        {
            cin >> tmp;
            arr[tmp]++;
        }
        sort(arr, arr + n + 1, greater<int>());
        // f(i, 0, n)
        // {
        //     cout << arr[i] << ' ';
        // }
        // cout << '\n';
        int lastNonZeroHavingIndex;
        f(i, 0, n + 1)
        {
            int tmp1 = arr[i];
            if (arr[i] == 0)
            {
                lastNonZeroHavingIndex = i - 1;
                break;
            }
        }
        int answer = lastNonZeroHavingIndex + 1;
        f(i, 0, lastNonZeroHavingIndex + 1)
        {
            if (arr[i] > answer - i)
            {
                answer += (arr[i] - (answer - i) + 1) / 2;
            }
        }
        cout << answer << '\n';
    }
    return 0;
}