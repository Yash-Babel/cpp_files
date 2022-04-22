#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i, a, b) for (int i = a; i < b; i++)
const int mod = 1000000007;

lli sumGTR(const lli *arr, lli size, lli r)
{
    lli start = 0, end = size - 1, answer = 0;
    while (start != end)
    {
        lli sum = arr[start] + arr[end];
        if (sum <= r)
        {
            start++;
        }
        else
        {
            answer += (end - start);
            end--;
        }
    }
    return answer;
}
lli sumLTL(const lli *arr, lli size, lli l)
{
    lli start = 0, end = size - 1, answer = 0;
    while (start != end)
    {
        lli sum = arr[start] + arr[end];
        if (sum >= l)
        {
            end--;
        }
        else
        {
            answer += (end - start);
            start++;
        }
    }
    return answer;
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
        lli n, l, r;
        cin >> n >> l >> r;
        lli arr[n];
        f(i, 0, n)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        lli gtr = sumGTR(arr, n, r);
        lli ltl = sumLTL(arr, n, l);
        lli tmp = ((n * (n - 1)) / 2);
        lli answer = tmp - gtr - ltl;
        cout << answer << '\n';
    }
    return 0;
}