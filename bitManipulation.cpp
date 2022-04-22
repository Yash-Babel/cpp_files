#include <bits/stdc++.h>
using namespace std;
#define f(i, a, b) for (int i = a; i < b; i++)

// https://www.codingninjas.com/codestudio/guided-paths/competitive-programming/content/148629/offering/1877042

bool isPowerOf2(int x)
{
    return (x && !(x & (x - 1))); // the outside x is for the case of x = 0.
}
bool isOdd(int x)
{
    return (x & 1);
}
bool isKthBit1(int x, int k) // for kth bit from left and starting with k = 0.
{
    return (x & (1 << k));
}

int twoRaisedToTheRightMostBitIn(int x)
{
    return (x & ~(x - 1));
}

// Brian Kernighan’s Algorithm
int numberOf1BitsIn(int x) // time complexity is dependent on number of bits equal to 1, worst case O(log2(x))
{                          // hence better than just traversing through the binary representation.
    int answer = 0;
    while (x != 0)
    {
        x = (x & (x - 1));
        answer++;
    }
    return answer;
}

// For more tricks, go to link online 5 to see fourth and fifth point.
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    // cout << isPowerOf2(1024) << '\n';

    // cout << isOdd(2) << '\n';

    // cout << isKthBit1(2, 1) << '\n';

    cout << numberOf1BitsIn(1023) << '\n';
}