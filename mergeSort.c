#include <stdio.h>
#include <limits.h>

int INTMAX = INT_MAX;

void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    printf("n1: %d\n", n1);
    printf("n2: %d\n", n2);

    int A[n1 + 1];
    int B[n2 + 1];

    for (int i = 0; i < n1; i++)
        A[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        B[j] = arr[mid + j + 1];
    A[n1] = INTMAX;
    B[n2] = INTMAX;

    for (int i = 0; i <= n1; i++)
        printf("A: %d ", A[i]);
    printf("\n");
    for (int j = 0; j <= n2; j++)
        printf("B: %d ", B[j]);
    printf("\n");

    int i = 0;
    int j = 0;

    printf("Start merge\nArr:");
    for (int k = l; k <= r; k++)
    {
        if (A[i] <= B[j])
        {
            arr[k] = A[i];
            i++;
        }
        else
        {
            arr[k] = B[j];
            j++;
        }
        printf("%d ", arr[k]);
    }

    printf("\n\n");
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
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
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    printArr(arr, n);
}