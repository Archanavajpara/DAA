// Write a program to implement binary search algorithm using recursive method.
#include <stdio.h>
#include <time.h>

int binarySearchRecursive(int arr[], int low, int high, int key)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == key)
        return mid;

    if (arr[mid] < key)
        return binarySearchRecursive(arr, mid + 1, high, key);
    else
        return binarySearchRecursive(arr, low, mid - 1, key);
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
    int idx = binarySearchRecursive(arr, 0, n - 1, key);
    end = clock();

    if (idx != -1)
        printf("Element found at index %d\n", idx);
    else
        printf("Not found\n");

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by recursive binary search: %f seconds\n", time_taken);

    return 0;
}
