#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    FILE *fp;
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    // Generate random numbers (Average Case)
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % n;
    }

    fp = fopen("avg.txt", "w");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    // Write array to file
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%d\n", a[i]);
    }

    fclose(fp);

    clock_t start, end;
    double time_taken;

    start = clock();

    // Insertion Sort
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Execution Time = %lf seconds\n", time_taken);

    return 0;
}