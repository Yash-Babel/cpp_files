// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        map<int, int> x;
        map<int, int> y;
        int n, tmp;
        cin >> n;

        for (int i = 0; i < 4 * n - 1; i++)
        {
            cin >> tmp;
            x[tmp]++;
            cin >> tmp;
            y[tmp]++;
        }
        map<int, int>::iterator itx;
        map<int, int>::iterator ity;
        for (itx = x.begin(); itx != x.end(); itx++)
        {
            if (x[itx->first] % 2 == 1)
            {
                cout << itx->first << " ";
            }
        }
        for (ity = y.begin(); ity != y.end(); ity++)
        {
            if (y[ity->first] % 2 == 1)
            {
                cout << ity->first << endl;
            }
        }
        // for (auto xit : x)
        // {
        //     if (xit.second % 2 == 1)
        //     {
        //         cout << xit.first << " ";
        //     }
        // }
        // for (auto yit : y)
        // {
        //     if (yit.second % 2 == 1)
        //     {
        //         cout << yit.first << endl;
        //     }
        // }
    }
}
// 1
// 2
// 1 1
// 1 2
// 4 6
// 2 1
// 9 6
// 9 3
// 4 3