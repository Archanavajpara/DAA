// Merge Two Sorted Arrays Without Extra Space.
// Given two sorted arrays a[] and b[] of size n and m respectively, merge both the arrays and rearrange the elements such that the smallest n elements are in a[] and the remaining m elements are in b[]. All elements in a[] and b[] should be in sorted order.
// Examples:
// Input: a[] = [2, 4, 7, 10], b[] = [2, 3] ; Output: a[] = [2, 2, 3, 4], b[] = [7, 10]
// Explanation: Combined sorted array = [2, 2, 3, 4, 7, 10], array a[] contains smallest 4 elements: 2, 2, 3 and 4, and array b[] contains remaining 2 elements: 7, 10.

#include <stdio.h>
void main()
{
    int a[]={2, 4, 7, 10};
    int b[]={2, 3};
    int n=sizeof(a)/sizeof(a[0]);
    int m=sizeof(b)/sizeof(b[0]);
    for(int i=0;i<n;i++)
    {
        if(a[i]>b[0])
        {
            int temp=a[i];
            a[i]=b[0];
            b[0]=temp;
            int first=b[0];
            int k;
            for(k=1;k<m && b[k]<first;k++)
            {
                b[k-1]=b[k];
            }
            b[k-1]=first;
        }
    }
    printf("Array a[] after merging:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nArray b[] after merging:\n");
    for(int i=0;i<m;i++)
    {
        printf("%d ",b[i]);
    }
}