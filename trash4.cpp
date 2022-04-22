#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i, a, b) for (long long int i = a; i < b; i++)
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
        lli n, k;
        cin >> n >> k;
        if (k > (n * (n - 1)) / 2)
        {
            cout << -1;
        }
        else
        {
            lli start = 1, end = n;
            for (lli i = n - 1; i >= 0; i--)
            {
                if (k >= i)
                {
                    k -= i;
                    cout << end << ' ';
                    end--;
                }
                else
                {
                    cout << start << ' ';
                    start++;
                }
            }
        }
        cout << '\n';
    }
    return 0;
}