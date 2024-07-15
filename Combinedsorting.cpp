#include<bits/stdc++.h>
using namespace std;
void bubblesort(int a[],int n){
    bool flag=false;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            while(a[i]<a[j]){
                swap(a[i],a[j]);
                flag=true;
            }
        }
        if(!flag){
            break;
        }
    }

}
void insertionsort(int a[],int n){
    for(int i=0;i<n;i++){
        for(int j=i;j>=0;j--){
            if(a[j-1]>a[j]&&j>0){
                swap(a[j-1],a[j]);
            }
        }
    }
}
void selectionsort(int a[],int n){
    for(int i=0;i<n;i++){
        int mini=i;
        for(int j=i;j<n;j++){
            if(a[j]<a[i]){
                mini=j;
            }
        }
        swap(a[mini],a[i]);
    }
}
void merge(int a[],int low,int mid,int high){
    int n1=mid-low+1;//number of element in the right hand side array
    int n2=high-mid;
    int a1[n1];
    int a2[n2];
    for(int i=0;i<n1;i++){
        a1[i]=a[low+i];
    }
    for(int i=0;i<n2;i++){
        a2[i]=a[mid+1+i];
    }
    int i=0,j=0,k=low;
    while(i<n1&&j<n2){
        if(a1[i]<a2[j]){
            a[k++]=a1[i++];
        }
        else{
            a[k++]=a2[j++];
        }
    }
    while(i<n1){
        a[k++]=a1[i++];
    }
    while(j<n2){
        a[k++]=a2[j++];
    }
}
void mergesort(int a[],int low,int high){
    if(low>=high)return;
    int mid=(low+high)/2;
    mergesort(a,mid+1,high);
    mergesort(a,low,mid-1);
    merge(a,low,mid,high);

}
int partition(int a[],int low,int high)
{
    int pivot=a[low];
    int i=low;
    int j=high;
    while(i<j)
    {
        while(a[i]<=pivot&&i<=high-1)
        {
            i++;
        }
        while(a[j]>pivot&&j>=low+1)
        {
            j--;
        }
        if(i<j)swap(a[i],a[j]);
    }
    swap(a[low],a[j]);
    return j;
}
void quicksort(int a[],int low,int high){
    if(low<high)
    {
        int pi=partition(a,low,high);
        quicksort(a,low,pi-1);
        quicksort(a,pi+1,high);
    }
}
int main(){
    int a[100];
    for(int i=0;i<100;i++){
        a[i]=rand();
    }
    int n=100;
    bubblesort(a,n);
    cout<<"After Bubble Sort"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    insertionsort(a,n);
    cout<<"After Insertion Sort"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    selectionsort(a,n);
    cout<<"After Selection Sort"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    mergesort(a,0,n-1);
    cout<<"After Merge Sort"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    quicksort(a,0,n-1);
    cout<<"After Quick Sort"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}