#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i, a, b) for (int i = a; i < b; i++)
const int mod = 1000000007;

lli GPmod(lli base, lli power, lli mod1)
{
    if (power == 0)
    {
        return 1;
    }
    if (power == 1)
    {
        return (base + 1) % mod1;
    }

    if (power % 2 == 0)
    {
        return (1 + (((base % mod1) * ((base + 1) % mod1) % mod1) * (GPmod((((base % mod1) * (base % mod1)) % mod1), (power / 2) - 1, mod1) % mod1)) % mod1) % mod1;
    }
    else
    {
        return (((base + 1) % mod1) * ((GPmod((((base % mod1) * (base % mod1)) % mod1), (power / 2), mod1) % mod1) % mod1)) % mod1;
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
        lli n, r, m;
        cin >> n >> r >> m;
        cout << GPmod(r, n, m) << '\n';
    }
    return 0;
}