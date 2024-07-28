#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of element you want in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int prefix_arr[n];
    prefix_arr[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix_arr[i] = prefix_arr[i - 1] + arr[i];
    }
    cout << "The prefix sum array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << prefix_arr[i] << " ";
    }
    cout << endl;
    return 0;
}