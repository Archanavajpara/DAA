// Write a program to implement binary search algorithm using linked list and recursive method.
#include <stdio.h>
#include <time.h>

int binarySearch_LinkedList(int arr[], int left, int right, int key)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] > key)
            return binarySearch_LinkedList(arr, left, mid - 1, key);

        return binarySearch_LinkedList(arr, mid + 1, right, key);
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
    int idx = binarySearch_LinkedList(arr, 0, n - 1, key);
    end = clock();

    if (idx != -1)
        printf("Element found at index %d\n", idx);
    else
        printf("Not found\n");

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by recursive binary search: %f seconds\n", time_taken);

    return 0;
}
