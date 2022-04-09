#include <bits/stdc++.h>
using namespace std;
bool isSame = true;
long long int powerFunction(long long int base, long long int power)
{
    long long int result = 1;
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
string kthChildNthGeneration(int n, long long int k)
{
    if (n == 1)
    {
        return "Male";
    }
    if (k == 1)
    {
        if (isSame)
        {
            return "Male";
        }
        else
        {
            isSame = true;
            return "Female";
        }
    }
    if (n == 2)
    {
        if (isSame ^ (k - 1))
        {
            isSame = true;
            return "Male";
        }
        else
        {
            isSame = true;
            return "Female";
        }
    }
    long long int twoPowerNMinusTwo = powerFunction((long long int)2, (long long int)(n - 2));
    if (k > twoPowerNMinusTwo)
    {
        isSame = !isSame;
        return kthChildNthGeneration(n - 1, k - twoPowerNMinusTwo);
    }
    else
    {
        return kthChildNthGeneration(n - 1, k);
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
        int n;
        long long int k;
        cin >> n >> k;
        string answer = kthChildNthGeneration(n, k);
        cout << answer << '\n';
    }
    return 0;
}