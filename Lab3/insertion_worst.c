#include <stdio.h>
#include <time.h>

void main()
{
    FILE *fp;
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    // Worst Case
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = n - i;
    }

    clock_t start, end;
    double time_taken;

    fp = fopen("worst.txt", "w");

    /* Write array to file */
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%d\n", a[i]);
    }

    fclose(fp);

    start = clock();

    /* Insertion Sort */
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
}