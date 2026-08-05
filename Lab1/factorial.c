#include <stdio.h>
#include <time.h>

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    clock_t start, end;
    double time;
    int n = 5;

    start = clock();
    int result = factorial(n);
    end = clock();
    time = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Factorial of %d is %d\n", n, result);
    printf("Time taken: %f seconds\n", time);

    return 0;
}
