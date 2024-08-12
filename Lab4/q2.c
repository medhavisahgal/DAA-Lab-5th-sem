//write a program to heapify an array of integers. The program should take the array as input and print the heapified array as output.
// The program should be implemented using a function named heapify. The function should have the following signature:
//build heap function
#include <stdio.h>
void heapify(int arr[], int n, int i)
{
    int largest = i;       
    int left = 2 * i ;  
    int right = 2 * i + 1; 
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}
void buildHeap(int arr[], int n)
{
    int startIdx = (n / 2) - 1;
    for (int i = startIdx; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    buildHeap(arr, n);

    printf("Heapified array is:\n");
    printArray(arr, n);

    return 0;
}

