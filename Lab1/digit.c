#include<stdio.h>
#include<time.h>
int digit(int n){
  if(n==0){
    return 1;
  }
  return 1 + digit(n/10);
}

int main(){
    clock_t start,end;
    double time;
    int num=123;

    start=clock();
    int count=digit(num);
    end=clock();
    time=((double)(end-start))/CLOCKS_PER_SEC;
    printf("time taken:%f\n",time);
    printf("count of digits are:%d\n",count);
    
}