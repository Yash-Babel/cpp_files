#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(i, a, b) for (int i = a; i < b; i++)
const int mod = 1000000007;
const int N = 32769;
int arr[N];
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
void preCompute()
{
    f(j, 1, 32769)
    {
        int answer = 0;
        int tmp = j;
        if (tmp % 2 == 1)
        {
            tmp += 1;
            answer += 1;
        }
        int n = tmp;
        int count = 0;
        while (n % 2 == 0)
        {
            count++;
            n /= 2;
        }
        int l2n = log2(tmp);
        if (powerFunction(2, l2n) == tmp)
        {
            answer += (15 - l2n);
        }
        else
        {
            for (int i = count; i < 15; i++)
            {
                int nextPowerOf2 = powerFunction(2, l2n + 1);
                if (15 - count > nextPowerOf2 - tmp + 14 - l2n)
                {
                    answer += nextPowerOf2 - tmp;
                    i = l2n;
                }
                else
                {
                    answer++;
                }
                l2n++;
                nextPowerOf2 *= 2;
                tmp *= 2;
            }
        }
        arr[j] = answer;
        // int tmp, n = j;
        // int answer = 0;
        // if (n % 2 == 1)
        // {
        //     n += 1;
        //     answer += 1;
        // }
        // tmp = n;
        // int count = 0;
        // while (n % 2 == 0)
        // {
        //     count++;
        //     n /= 2;
        // }
        // n = tmp;
        // answer += (15 - count);
        // for (int i = 0; i < 15 - count; i++)
        // {
        //     answer = min(answer, 32768 - ((2 * n) % 32768) + i + 1);
        //     n = ((2 * n) % 32768);
        // }
        // answer = min(answer, 32768 - tmp);
        // arr[j] = answer;
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
    preCompute();
    while (t--)
    {
        int n;
        cin >> n;
        cout << arr[n];
        // int n, tmp;
        // cin >> n;
        // tmp = n;
        // int answer = 0;
        // if (n % 2 == 1)
        // {
        //     n += 1;
        //     answer += 1;
        // }
        // int count = 0;
        // while (n % 2 == 0)
        // {
        //     count++;
        //     n /= 2;
        // }
        // answer += (15 - count);
        // for (int i = 0; i < 15 - count; i++)
        // {
        //     answer = min(answer, 32768 - ((2 * n) % 32768) + i + 1);
        //     n = ((2 * n) % 32768);
        // }
        // answer = min(answer, 32768 - tmp);
        cout << "\n";
    }
    return 0;
}