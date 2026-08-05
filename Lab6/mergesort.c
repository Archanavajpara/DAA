// Write a program to implement merge sort algorithm.
#include <stdio.h>
#include <time.h>

int merge(int arr[], int lb, int mid, int ub)
{
    int i = lb;
    int j = mid + 1;
    int k = lb;
    int temp[ub + 1];

    while (i <= mid && j <= ub)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= ub)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int l = lb; l <= ub; l++)
        arr[l] = temp[l];

    return 0;
}

int mergeSort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = lb + (ub - lb) / 2;
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
    return 0;
}

void main()
{
    clock_t start, end;
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid n\n");
        return;
    }

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();

    printf("Sorted array: [ ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("]");
    printf("\n");

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by merge sort: %f seconds\n", time_taken);
}
