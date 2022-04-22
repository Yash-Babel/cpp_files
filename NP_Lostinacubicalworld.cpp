#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i, a, b) for (int i = a; i < b; i++)
const int mod = 1000000007;

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
    int t = 1;
    cin >> t;
    while (t--)
    {
        double n;
        cin >> n;
        double x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        double xdiff = abs(x2 - x1);
        double ydiff = abs(y2 - y1);
        double a = (ydiff * ydiff) + (n + abs(x2 - 0) + abs(0 - x1)) * (n + abs(x2 - 0) + abs(0 - x1));
        double b = (ydiff * ydiff) + (n + abs(x2 - n) + abs(n - x1)) * (n + abs(x2 - n) + abs(n - x1));
        double c = (xdiff * xdiff) + (n + abs(y2 - n) + abs(n - y1)) * (n + abs(y2 - n) + abs(n - y1));
        double d = (xdiff * xdiff) + (n + abs(y2 - 0) + abs(0 - y1)) * (n + abs(y2 - 0) + abs(0 - y1));
        double answer = sqrt(min(a, min(b, min(c, d))));
        cout << fixed;
        cout << setprecision(9) << answer << '\n';
        // printf("%.9lf\n", answer);
    }
    return 0;
}