#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i, a, b) for (int i = a; i < b; i++)
const int mod = 1000000007;

int solve(int N, int S)
{
    int rem = S % N;
    int qu = S / N;
    int answer = 1;
    for (int i = 0; i < N - 1; i++)
    {
        answer *= qu;
        if (answer > (1e6 + 10) / qu)
        {
            break;
        }
    }
    answer *= (qu + rem);
    if (answer <= 1e6 || answer < 0)
    {
        answer = S - N + 1;
    }
    else
    {
        answer = min(answer, S - N + 1);
    }
    return answer;
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
    // cin >> t;
    while (t--)
    {
        int n = 1680, s = 56908;
        string a = "vohxjbcxve";
        // long long a[] = {1, 1, 1};
        long long b[] = {1, 2, 3, 4};
        cout << solve(n, s);
        // cout << 'g' - 'u';
    }
    return 0;
}