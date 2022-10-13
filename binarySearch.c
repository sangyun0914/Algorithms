#include <stdio.h>

int binarySearch(int arr[], int key, int l, int r)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2; // Avoid overflow
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            r = mid - 1;
        else if (arr[mid] < key)
            l = mid + 1;
    }
    return -1;
}

int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 3;
    int idx = binarySearch(arr, key, 0, n - 1);
    printf("Idx: %d\n", idx);
}