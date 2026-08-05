#include<stdio.h>
#include<time.h>

void consecutive(int n){
    int i,l=0,r=0;
    int sum=0;
    for(i=1;i<=n/2;i++){
        sum+=i;
        while(sum<n){
            sum+=r;
            r++;
        }
        while(sum>n){
            sum-=l;
            l++;
        }
         if(sum==n){
            printf("Consecutive numbers are: ");
            for(int j=l+1;j<=r+1;j++){
                printf("%d+",j);
            }
        }
    }
}
int main(){
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    clock_t start, end;
    double time;
    start = clock();
    consecutive(n);
    end = clock();
    time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time);
    return 0;
}