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
lli gcd(lli a, lli b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int mex(int arr[], int n)
{
    int MEXMinusOne = -1;
    f(i, 0, n)
    {
        if (arr[i] == MEXMinusOne + 1)
        {
            MEXMinusOne++;
        }
        else if (arr[i] == MEXMinusOne)
        {
            continue;
        }
        else
        {
            break;
        }
    }
    return (MEXMinusOne + 1);
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
        int n;
        cin >> n;
        int arr[n];
        f(i, 0, n)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        int MEX = mex(arr, n);
        if (MEX == 1)
        {
            cout << -1;
        }
        else if (MEX == 0)
        {
            cout << arr[0] - 1;
        }
        else
        {
            int answer = 0;
            int count = 1;
            f(i, 1, n)
            {
                if (arr[i] - arr[i - 1] != 1)
                {
                    if (count >= MEX - 1)
                    {
                        answer++;
                    }
                    count = 1;
                }
                else
                {
                    count++;
                }
            }
            if (count >= MEX - 1)
            {
                answer++;
            }
            cout << answer - 1;
        }
        cout << '\n';
    }
    return 0;
}