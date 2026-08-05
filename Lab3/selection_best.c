#include <stdio.h>
#include <time.h>

void main()
{
    FILE *fp;
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    // Best Case
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }

    clock_t start, end;
    double time_taken;

    fp = fopen("best.txt", "w");

    /* Write array to file */
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%d\n", a[i]);
    }

    fclose(fp);

    start = clock();

    /* Selection Sort */
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }

        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Execution Time = %lf seconds\n", time_taken);
}