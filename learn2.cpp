#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x = 20;
    int y = 10;
    swap(&x, &y);
    cout << "The value of x = " << x << "\n";
    cout << "The value of y = " << y;
}