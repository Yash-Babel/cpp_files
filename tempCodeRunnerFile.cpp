#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i, a, b) for (int i = a; i < b; i++)
const int mod = 1000000007;

lli powerFunction(lli base, lli power)
{
    lli result = 1;
    while (power > 0)
    {
        if (power % 2 == 0)
        {
            power /= 2;
            base *= base;
        }
        else
        {
            result *= base;
            power -= 1;
        }
    }
    return result;
}
bool isPrime(lli a)
{
    if (a == 0 || a == 1 || a == -1)
    {
        return false;
    }
    else if (a == 2)
    {
        return true;
    }
    for (lli i = 2; i < sqrt(a) + 1; i++)
    {
        if (a % i == 0)
        {
            return false;
        }
    }
    return true;
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
        int n;
        cin >> n;
        int arr[n], brr[n];
        f(i, 0, n)
        {
            cin >> arr[i];
        }
        f(i, 0, n)
        {
            cin >> brr[i];
        }
        f(i, 0, n)
        {
            if (arr[i] > brr[i])
            {
                swap(arr[i], brr[i]);
            }
        }
        lli answer = 0;
        f(i, 0, n - 1)
        {
            answer = answer + abs(arr[i + 1] - arr[i]) + abs(brr[i + 1] - brr[i]);
        }
        cout << answer;
        cout << "\n";
    }
    return 0;
}