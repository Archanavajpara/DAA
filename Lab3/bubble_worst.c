#include <stdio.h>
#include <time.h>

int main()
{
    FILE *fp;

    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int a[n];

    // Worst Case (Reverse Sorted Data)
    for (int i = 0; i < n; i++)
    {
        a[i] = n - i;
    }

    clock_t start, end;
    double time_taken;

    fp = fopen("worst.txt", "w");

    for (int i = n; i >= 1; i--)
    {
        fprintf(fp, "%d\n", i);
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

    return 0;
}