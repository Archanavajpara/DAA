#include <stdio.h>
#include <time.h>

int sum(int n){
    if(n==0 || n==1){
        return 1;
    }
    return n + sum(n-1);
}
int main(){
    clock_t start,end;
    double time;
    int num;
    
    printf("Enter a number:");
    scanf("%d",&num);
    start=clock();
    int result=sum(num);
    end=clock();
    time=((double)(end-start))/ CLOCKS_PER_SEC;

    printf("sum of %d is %d\n",num,result);
    printf("Time taken:%f seconds\n",time);

    return 0;
}
