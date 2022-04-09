#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const int mod = 1000000007;

lli powerFunction2(lli base, lli power)
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

lli countTheOnes(lli n, lli k)
{
    if (n == 1 || k <= n)
    {
        return k;
    }
    lli twoPowerNMinusOne = powerFunction2(2, n - 1);
    if (k <= twoPowerNMinusOne)
    {
        return 1 + countTheOnes(n - 1, k - 1);
    }
    else
    {
        return (twoPowerNMinusOne + (n - 3) * (twoPowerNMinusOne / 2) + 1) + (countTheOnes(n - 1, k - twoPowerNMinusOne) + k - twoPowerNMinusOne);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        lli n, k;
        cin >> n >> k;
        lli answer = countTheOnes(n, k);
        cout << answer << "\n";
    }
    return 0;
}