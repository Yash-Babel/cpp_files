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
        int n;
        cin >> n;
        int arr[n];
        int even = 0, odd = 0;
        f(i, 0, n)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        f(i, 0, n - 1)
        {
            even += ((arr[n - 1] - arr[i]) / 2) * 2;
            odd += ((arr[n - 1] - arr[i]) % 2);
        }
        int answer = 0;
        if (even / 2 == odd)
        {
            answer += even;
        }
        else if (even / 2 > odd)
        {
            answer += odd * 2;
            even -= odd * 2;
            answer += ((even / 3) * 2 + (even % 3));
        }
        else
        {
            answer += even;
            odd -= even / 2;
            answer += 2 * odd - 1;
        }
        cout << answer << '\n';
    }
    return 0;
}