#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i, a, b) for (int i = a; i < b; i++)
const int mod = 1000000007;

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
        lli a = 5, b = 9, k;
        cin >> a >> b >> k;
        bool aliceWin, switching = false;
        while (true)
        {
            if (2 * a < b)
            {
                if ((b / (2 * a)) % 2 == 1)
                {
                    switching = !switching;
                }
                b = (b % (2 * a));
                if (b == 0)
                {
                    // b += (2 * a);
                    // switching = !switching;
                    break;
                }
            }
            else if (2 * b < a)
            {
                if ((a / (2 * b)) % 2 == 1)
                {
                    switching = !switching;
                }
                a = (a % (2 * b));
                if (a == 0)
                {
                    // a += (2 * b);
                    // switching = !switching;
                    break;
                }
            }
            else
            {
                break;
            }
        }
        if (a == 0)
        {
            aliceWin = true;
        }
        else if (b == 0)
        {
            aliceWin = false;
        }
        else
        {
            while (true)
            {
                a = abs(a - b);
                if (a == 0)
                {
                    aliceWin = true;
                    break;
                }
                b = abs(a - b);
                if (b == 0)
                {
                    aliceWin = false;
                    break;
                }
            }
        }
        if ((aliceWin ^ switching) == 1)
        {
            cout << "Alice\n";
        }
        else
        {
            cout << "Bob\n";
        }
    }
    return 0;
}