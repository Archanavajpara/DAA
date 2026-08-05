// Move all Zeros to End of Array.
// Given an array of integers arr[], move all the zeros to the end of the array while maintaining the relative order of all non-zero elements.
// Examples:
// Input: arr[] = [1, 2, 0, 4, 3, 0, 5, 0]; Output: [1, 2, 4, 3, 5, 0, 0, 0]

#include <stdio.h>

void main()
{
    int arr[] ={1, 2, 0, 4, 3, 0, 5, 0};
    int n=sizeof(arr)/sizeof(arr[0]);
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=0){
            arr[j++]=arr[i];
        }
    }
    while(j<n)
    {
        arr[j++]=0;
    }

    printf("Array after moving zerpes to end:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}