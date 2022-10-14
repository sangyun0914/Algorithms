#include <stdio.h>

void swap(int arr[], int var1, int var2)
{
    int temp = arr[var1];
    arr[var1] = arr[var2];
    arr[var2] = temp;
}

void selectionSort(int arr[], int n)
{
    int min;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        if (i != min)
            swap(arr, i, min);
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
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    printArr(arr, n);
}