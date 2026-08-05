// Given a 2D array arr[][] where arr[i][0] represents the starting time and arr[i][1] represents the ending time of the ith meeting, determine whether it is possible for a person to attend all meetings without any overlaps, considering that a person can attend only one meeting at any given time.


#include <stdio.h>

int canAttendMeetings(int arr[][2], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j][0] > arr[j + 1][0]) {
                int tempStart = arr[j][0];                                                                                                                                                                                                  
                int tempEnd = arr[j][1];
                arr[j][0] = arr[j + 1][0];
                arr[j][1] = arr[j + 1][1];
                arr[j + 1][0] = tempStart;
                arr[j + 1][1] = tempEnd;
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (arr[i][1] > arr[i + 1][0]) {
            return 0;
        }
    }
    return 1;
}
int main() {
    int arr[][2] = {{2, 4}, {1, 2}, {7, 8}, {5, 6}, {6, 8}};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (canAttendMeetings(arr, n)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}   