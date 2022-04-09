#include <bits/stdc++.h>
using namespace std;

// Majority Element is the one which comes more than n/2 times in that array.
int majorityElement(int arr[], int size)
{
    int candidate = arr[0];
    int votesAndCount = 1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == candidate)
        {
            votesAndCount++;
        }
        else
        {
            votesAndCount--;
        }
        if (votesAndCount == 0)
        {
            candidate = arr[i];
            votesAndCount++;
        }
    }
    votesAndCount = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == candidate)
        {
            votesAndCount++;
        }
    }
    if (votesAndCount > size / 2)
    {
        return candidate;
    }
    else
    {
        return -1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {1, 1, 1, 1, 1, 6, 7, 1, 10, 11};
    cout << majorityElement(arr, 10);
}