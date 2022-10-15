#include <stdio.h>
#include <limits.h>

typedef struct indexes
{
    int low;
    int high;
    int sum;
} indexes;

indexes FindMaximumCrossingSubArray(int A[], int low, int mid, int high)
{
    int left_sum = INT_MIN;
    int max_left, max_right;
    int sum = 0;

    for (int i = mid; i > low; i--)
    {
        sum = sum + A[i];
        if (sum > left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum = INT_MIN;
    sum = 0;
    for (int j = mid + 1; j < high; j++)
    {
        sum = sum + A[j];
        if (sum > right_sum)
        {
            right_sum = sum;
            max_right = j;
        }
    }
    indexes res = {max_left, max_right, left_sum + right_sum};
    return res;
}

indexes FindMaximumSubArray(int A[], int low, int high)
{
    if (high == low)
    {
        indexes res = {low, high, A[low]};
        return res;
    }
    else
    {
        int mid = (low + high) / 2;
        indexes leftIndex = FindMaximumSubArray(A, low, mid);
        indexes rightIndex = FindMaximumSubArray(A, mid + 1, high);
        indexes crossIndex = FindMaximumCrossingSubArray(A, low, mid, high);

        if (leftIndex.sum >= rightIndex.sum && leftIndex.sum >= crossIndex.sum)
            return leftIndex;
        else if (rightIndex.sum >= leftIndex.sum && rightIndex.sum >= crossIndex.sum)
            return rightIndex;
        else
            return crossIndex;
    }
}

int main()
{
    int arr[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    indexes result = FindMaximumSubArray(arr, 0, n - 1);
    printf("Left index: %d\n", result.low);
    printf("Right index: %d\n", result.high);
    printf("Sum: %d\n", result.sum);
}