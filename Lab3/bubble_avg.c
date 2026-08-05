#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void main()
{
    FILE *fp;

    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int a[n];

    // Average Case (Random Data)
    for (int i = 0; i < n; i++)
    {
        a[i] = rand();      
    }

    clock_t start, end;
    double time_taken;

    fp = fopen("average.txt", "w");

    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%d\n", a[i]);
    }

    fclose(fp);

    start = clock();

    // Bubble Sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Execution Time = %lf seconds\n", time_taken);

}