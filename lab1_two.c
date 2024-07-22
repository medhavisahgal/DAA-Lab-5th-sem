#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        a[i]=rand();
    }
    printf("Array is:\n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    int prefix[n];
    prefix[0]=a[0];
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+a[i];
    }
    printf("Prefix sum array is:\n");
    for(int i=0;i<n;i++){
        printf("%d ",prefix[i]);
    }
}