#include <stdio.h>
#include <time.h>

void main()
{
    // bubble sort best
    FILE *fp;

    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int a[n];

    // best case
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

    /* Bubble Sort */
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
