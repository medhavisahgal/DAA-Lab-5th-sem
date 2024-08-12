#include <stdio.h>
#include <stdlib.h>

void binary_search(int arr[], int low, int high, int x)
{
    if (low > high)
    {
        printf("Element not found\n");
        return;
    }
    int mid = (low + high) / 2;
    if (arr[mid] == x)
    {
        printf("Element found at index: %d\n", mid);
    }
    else if (arr[mid] < x)
    {
        binary_search(arr, mid + 1, high, x);
    }
    else
    {
        binary_search(arr, low, mid - 1, x);
    }
}

int main()
{
    int n;
    printf("Enter the size of the array\n");
    scanf("%d", &n);
    FILE *in = fopen("input.txt", "r");
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        fscanf(in, "%d", &arr[i]);
    }
    fclose(in);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Enter the element to be searched\n");
    int x;
    scanf("%d", &x);

    binary_search(arr, 0, n - 1, x);

    return 0;
}
