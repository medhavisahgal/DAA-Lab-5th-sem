// binary search using recursion
#include <bits/stdc++.h>
using namespace std;
void binary_search(int arr[], int low, int high, int x)
{
    if (low > high)
    {
        cout << "Element not found" << endl;
        return;
    }
    int mid = (low + high) / 2;
    if (arr[mid] == x)
    {
        cout << "Element found at index : " << mid << endl;
    }
    else if (arr[mid] < x)
    {
        binary_search(arr, mid + 1, high, x);
    }
    else if (arr[mid] > x)
    {
        binary_search(arr, low, mid - 1, x);
    }
    return;
}
int main()
{
    int n;
    cout << "Enter the size of the array" << endl;
    cin >> n;
    ifstream in("input.txt");
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        in >> arr[i];
    }
    sort(arr, arr + n);
    cout << "Enter the element to be searched" << endl;
    int x;
    cin >> x;
    binary_search(arr, 0, n - 1, x);
}