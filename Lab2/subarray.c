#include<stdio.h>
#include <time.h>

void subarray(int n){
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int k=i;k<=j;k++){
                printf("%d ",k);
            }
            printf("\n");
        }
    }
    printf("\n");
}
int main(){
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    clock_t start, end;
    double time;
    start = clock();
    subarray(n);
    end = clock();
    time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time);
    return 0;
}