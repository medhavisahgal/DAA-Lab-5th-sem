#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Number of elements you want to read from the file: " << endl;
    cin >> n;
    ifstream inputFile("input.txt");
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        inputFile >> arr[i];
    }
    inputFile.close();
    cout << "The numbers read from the file are: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    sort(arr, arr + n);
    int highest = arr[n - 1];
    int lowest = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != lowest)
        {
            cout << "Second smallest number is : " << arr[i] << endl;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] != highest)
        {
            cout << "Second largest number is : " << arr[i] << endl;
            break;
        }
    }
    return 0;
    // g++ -Wextra -std=c++17 -o q1 q1.cpp
    //.\q1.exe
}