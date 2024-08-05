#include <bits/stdc++.h>
using namespace std;
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
    sort(arr, arr + n);
    cout << "Enter the element to be searched" << endl;
    int x;
    cin >> x;
    int low = 0;
    int high = n - 1;
    bool found = false;
    int count = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            cout << "Element found at index : " << mid << endl;
            found = true;
            break;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
        count++;
    }
    if (!found)
    {
        cout << "Element not found" << endl;
    }
    cout << "Number of comparisons : " << count << endl;
    return 0;
}