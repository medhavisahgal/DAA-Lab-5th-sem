// time for selection and bubble sort and make graph for it for
// array ize greater than 10000
#include <bits/stdc++.h>
using namespace std;
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
int main()
{
    int n;
    cout << "Enter the size of the array" << endl;
    cin >> n;
    int arr[n];
    ifstream in("input.txt");
    for (int i = 0; i < n; i++)
    {
        in >> arr[i];
    }
    in.close();
    clock_t start, end;
    start = clock();
    bubbleSort(arr, n);
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by Bubble Sort : " << fixed << time_taken << setprecision(5)<<endl;
    clock_t start1, end1;
    start1 = clock();
    selectionSort(arr, n);
    end1 = clock();
    double time_taken1 = double(end1 - start1) / double(CLOCKS_PER_SEC);
    cout << "Time taken by Selection Sort : " << fixed << time_taken1 << setprecision(5);
}
// compile using g++ q3.cpp -o q3
// run using ./q3