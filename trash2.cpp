#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i, a, b) for (int i = a; i < b; i++)
const int mod = 1000000007;

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

bool checkPalindrome(long long N)
{
	long long ln = log2(N);
    int tmp = N;
    for(int i = 0; i <= ln; i++){
        tmp = (tmp ^ (1 << i));
    }
    if(N ^ tmp){
        return false;
    }
    return true;
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
        long long n;
        cin >> n;
        cout << checkPalindrome(n) << '\n';
    }
    return 0;
}