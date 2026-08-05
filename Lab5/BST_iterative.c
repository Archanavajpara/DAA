// Write a program to implement binary search algorithm using iterative method.

#include <stdio.h>
#include <time.h>

int binarySearchIterative(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main(void)
{
    clock_t start, end;
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid n\n");
        return 0;
    }

    int arr[n];
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int key;
    printf("Enter element to search: ");
    scanf("%d", &key);

    start = clock();
    int idx = binarySearchIterative(arr, n, key);
    end = clock();

    if (idx != -1)
        printf("Element found at index %d\n", idx);
    else
        printf("Not found\n");

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by iterative binary search: %f seconds\n", time_taken);

    return 0;
}
