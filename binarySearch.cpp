#include <bits/stdc++.h>
using namespace std;
bool binarySearchSortedArray(int arr[], int size, int target)
{
    int start = 0, end = size - 1, tmp, mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        tmp = arr[mid];
        if (tmp == target)
        {
            return true;
        }
        else if (tmp > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Sorted array
    int size = 9;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 10;
    if (binarySearchSortedArray(arr, size, target))
    {
        cout << "Target elememt is found";
    }
    else
    {
        cout << "Target elememt is not found";
    }
    return 0;
}