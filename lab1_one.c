#include<stdio.h>
#include<stdbool.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        a[i]=rand();
    }
    bool flag=false;
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        flag=false;
        for(int j=0;j<n-1;j++){
            if(a[j]>a[j+1]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                flag=true;
            }
        }
        if(!flag){
            break;
        }
    }
    
    printf("Second smallest element is %d \n",a[1]);
    printf("Second largest element is %d",a[n-2]);
}