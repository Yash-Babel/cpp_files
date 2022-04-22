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
        int n, tmp, even = 0, odd = 0;
        cin >> n;
        int arr[n];
        int answer = 1e9;
        f(i, 0, n)
        {
            cin >> tmp;
            if (tmp % 2 == 0)
            {
                even++;
            }
            else
            {
                odd++;
            }
            arr[i] = tmp;
        }
        int sameBefore, sameNotBefore = 0, diffAfter = 0, diffNotAfter, isOdd;
        if (arr[0] % 2 == 0)
        {
            isOdd = 0;
            sameBefore = even;
            diffNotAfter = odd;
        }
        else
        {
            isOdd = 1;
            sameBefore = odd;
            diffNotAfter = even;
        }
        if (diffNotAfter == 0)
        {
            cout << n << '\n';
        }
        else if ((arr[0] % 2) ^ (arr[n - 1] % 2) == 0)
        {
            cout << (sameBefore - 1) << '\n';
        }
        else
        {
            for (int i = n - 1; i > 0; i--)
            {
                int parity = arr[i] % 2;
                if (parity ^ isOdd == 1)
                {
                    diffAfter++;
                    diffNotAfter--;
                    if ((arr[i - 1] % 2) ^ (arr[i] % 2) == 0)
                    {
                        continue;
                    }
                }
                if (diffNotAfter == 0)
                {
                    tmp = diffAfter;
                }
                else
                {
                    tmp = (sameBefore - 1 + diffAfter);
                }
                answer = min(answer, tmp);
                if (parity ^ isOdd == 0)
                {
                    sameBefore--;
                    sameNotBefore++;
                }
            }
            cout << min(answer, n) << '\n';
        }
    }
    return 0;
}