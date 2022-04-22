#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i, a, b) for (int i = a; i < b; i++)

long long int binpow(long long int a, long long int b, long long int m)
{
    a %= m;
    long long int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    lli n, k, m;
    cin >> n >> k >> m;
    if (k == 0)
    {
        cout << n % m << "\n";
    }
    else
    {
        lli quotient = n / m;
        lli remainder = n % m;
        lli ans = 0;
        lli extra = 0;
        f(i, 1, m)
        {
            lli tmp = binpow(i, k, m);
            ans += tmp;
            ans %= m;
            if (i == remainder)
            {
                extra = ans;
            }
        }
        lli answer = ((quotient % m) * (ans % m)) % m;
        answer += (extra % m);
        answer %= m;
        cout << answer << "\n";
    }
    return 0;
}