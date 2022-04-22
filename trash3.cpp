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

double FindXIntercept(double xnot, double ynot, double m)
{
    return (xnot - (ynot / m));
}
double FindMByYIntercept(double xnot, double ynot, double yIntercept)
{
    return (ynot - yIntercept) / xnot;
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
    // int t = 1;
    // cin >> t;
    // while (t--)
    // {
    lli a, b;
    cin >> a >> b;
    lli xIntercept = a;
    xIntercept++;
    lli yIntercept = b + 1;
    lli answer = 0;
    while (yIntercept >= b + 1)
    {
        lli tmp;
        if ((xIntercept * b) % (xIntercept - a) == 0)
        {
            tmp = (xIntercept * b) / (xIntercept - a);
            if (tmp >= b + 1)
            {
                answer++;
            }
        }
        if ((xIntercept * b) / (xIntercept - a) < b + 1)
        {
            break;
        }
        xIntercept++;
    }
    cout << answer;
    // }
    // double x = 2.5;
    // double tmp = modf(1.2, &x);
    // cout << tmp;
    return 0;
}