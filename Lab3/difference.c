// Given an unsorted array, find the minimum difference between any pair in the given array using sorting approad.

#include <stdio.h>

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int findMinDifference(int arr[], int n) {
    sort(arr, n);
    int minDiff = arr[1] - arr[0];
    for (int i = 1; i < n - 1; i++) {
        int diff = arr[i + 1] - arr[i];
        if (diff < minDiff) {
            minDiff = diff;
        }
    }
    return minDiff;
}
int main() {
    int arr[] = {25,8,75,5,2,19,17};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array 
    int minDiff = findMinDifference(arr, n);
    printf("Minimum difference is: %d\n", minDiff);
    return 0;
}   