#include <stdio.h>

int binarySearch(int arr[], int key, int l, int r)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == key)
            return mid + 1;
        else if (arr[mid] > key)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}

void binaryInsertionSort(int arr[], int n)
{
    int key, loc;

    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        key = arr[i];

        loc = binarySearch(arr, key, 0, j);

        for (; j >= loc; j--)
            arr[j + 1] = arr[j];
        arr[loc] = key;
    }
}

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    // int arr[] = {37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54};
    int arr[] = {8, 6, 1, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    binaryInsertionSort(arr, n);
    printArr(arr, n);
}