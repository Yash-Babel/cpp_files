#include <bits/stdc++.h>
using namespace std;
#define lli long long int
const int mod = 1000000007;
const int mod1 = 998244353;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string str;
        cin >> n >> str;
        lli answer = 0;
        lli arr[n];
        arr[0] = str[0] - '0';
        for (int i = 1; i < n; i++)
        {
            arr[i] = (arr[i - 1] + (str[i] - '0') * (i + 1)) % 2;
        }
        lli tmp = 2;
        for (int i = 0; i < n; i++)
        {
            answer = (answer * 2 + arr[i]) % mod1;
        }
        cout << answer << "\n";
    }
}
