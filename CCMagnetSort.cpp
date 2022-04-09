#include <bits/stdc++.h>
using namespace std;

#define lli long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        vector<int> v;
        string str;
        int tmp;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            v.push_back(tmp);
        }
        cin >> str;
        if (is_sorted(v.begin(), v.end()))
        {
            cout << 0 << "\n";
        }
        else
        {
            int count = 0;
            int arr[n];
            for (int i = 0; i < n; i++)
            {
                if (str[i] == 'N')
                {
                    arr[i] = 1;
                    count += 1;
                }
                else if (str[i] == 'S')
                {
                    arr[i] = -1;
                    count += -1;
                }
            }
            if (count == n || count == (-1 * n))
            {
                cout << -1 << "\n";
            }
            else
            {
                if (arr[0] * arr[n - 1] == -1)
                {
                    cout << 1 << "\n";
                }
                else
                {
                    // vector<int> v1 = v;
                    // sort(v1.begin(), v1.end());
                    // int first = n, last = 0;
                    // for (int j = 0; j < n; j++)
                    // {
                    //     if (v[j] != v1[j])
                    //     {
                    //         first = min(j, first);
                    //         last = max(j, last);
                    //     }
                    // }
                    // bool b1 = false, b2 = false;
                    // for (int j = 0; j < first; j++)
                    // {
                    //     if (str[j] != str[last])
                    //     {
                    //         b1 = true;
                    //         break;
                    //     }
                    // }
                    // for (int j = n - 1; j > last; j--)
                    // {
                    //     if (str[j] != str[first])
                    //     {
                    //         b2 = true;
                    //         break;
                    //     }
                    // }
                    // if (str[first] != str[last] || b1 || b2)
                    // {
                    //     cout << 1 << "\n";
                    // }
                    // else
                    // {
                    //     cout << 2 << "\n";
                    // }

                    //////////   OR

                    // vector<int> v1 = v;
                    // int index;
                    // for (int i = n - 2; i > 0; i--)
                    // {
                    //     if (str[i] != str[0])
                    //     {
                    //         index = i;
                    //         break;
                    //     }
                    // }
                    // sort(v1.begin(), v1.begin() + index + 1);
                    // if (is_sorted(v1.begin(), v1.end()))
                    // {
                    //     cout << 1 << "\n";
                    // }
                    // else
                    // {
                    //     vector<int> v2 = v;
                    //     for (int i = 1; i < n - 1; i++)
                    //     {
                    //         if (str[i] != str[n - 1])
                    //         {
                    //             index = i;
                    //             break;
                    //         }
                    //     }
                    //     sort(v2.begin() + index, v2.end());
                    //     if (is_sorted(v2.begin(), v2.end()))
                    //     {
                    //         cout << 1 << "\n";
                    //     }
                    //     else
                    //     {
                    //         cout << 2 << "\n";
                    //     }
                    // }
                }
            }
        }
    }
    return 0;
}
