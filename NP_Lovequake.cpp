#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i, a, b) for (int i = a; i < b; i++)
const int mod = 1000000007;

const int N = 1e6 + 1;

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
int powerFunction(int base, int power)
{
    int result = 1;
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
        lli n, m;
        lli tmp;
        cin >> n >> m;
        vector<pair<lli, lli>> h_eqM(N, {0, 0});
        lli BWH[n];
        lli CWE[m];
        for (lli i = 0; i < n; i++)
        {
            cin >> BWH[i];
        }
        for (lli i = 0; i < n; i++)
        {
            cin >> tmp;
            h_eqM[BWH[i]].first = tmp;
        }
        for (lli i = 0; i < m; i++)
        {
            cin >> CWE[i];
        }
        for (lli i = 0; i < m; i++)
        {
            cin >> tmp;
            h_eqM[CWE[i]].second = tmp;
        }
        lli currentQuake = 0;
        for (lli i = 1; i < N; i++)
        {
            if (h_eqM[i].second > currentQuake)
            {
                currentQuake = h_eqM[i].second;
            }
            if (h_eqM[i].first - currentQuake <= 0)
            {
                h_eqM[i].first -= currentQuake;
            }
            if (currentQuake > 0)
            {
                currentQuake--;
            }
        }
        currentQuake = 0;
        for (lli i = N - 1; i > 0; i--)
        {
            if (h_eqM[i].second > currentQuake)
            {
                currentQuake = h_eqM[i].second;
            }
            if (h_eqM[i].first - currentQuake <= 0)
            {
                h_eqM[i].first -= currentQuake;
            }
            if (currentQuake > 0)
            {
                currentQuake--;
            }
        }
        int answer = 0;
        for (lli i = 0; i < n; i++)
        {
            if (h_eqM[BWH[i]].first + h_eqM[BWH[i]].second > 0)
            {
                answer++;
            }
            // cout << h_eqM[BWH[i]].first + h_eqM[BWH[i]].second << ' ';
        }
        cout << answer << '\n';
    }
    return 0;
}