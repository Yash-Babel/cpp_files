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
    int i1 = 30;
    int i2 = 30; //(i2 * (i2 + 1) * 3) / 2
    int i3 = 20;
    int answer = 0;
    f(i, 1, i1 + 1)
    {
        f(j, 1, i2 + 1)
        {
            f(k, 0, i3 + 1)
            {
                answer += (i & j & k);
            }
            // cout << i << " & " << j << " = " << (i & j) << '\n';
        }
    }
    cout << answer;
    return 0;
}