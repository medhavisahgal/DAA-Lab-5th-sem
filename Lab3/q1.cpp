#include<bits/stdc++.h>
using namespace std;
void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
    }
}
int main(){
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int arr[n];
    ifstream in("input.txt");
    for(int i=0;i<n;i++){
        in>>arr[i];
    }
    in.close();
    sort(arr,arr+n);
    clock_t start,end;
    start=clock();
    insertionSort(arr,n);
    end=clock();
    double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
    cout<<"Time taken by insertion sort in best case is "<<fixed<<time_taken<<setprecision(5)<<endl;
    reverse(arr,arr+n);
    start=clock();
    insertionSort(arr,n);
    end=clock();
    time_taken=double(end-start)/double(CLOCKS_PER_SEC);
    cout<<"Time taken by insertion sort in worst case is "<<fixed<<time_taken<<setprecision(5)<<endl;
    return 0;
}