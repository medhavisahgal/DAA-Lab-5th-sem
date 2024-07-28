#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of elements you want to read from the file: " << endl;
    cin >> n;
    ifstream in("input.txt");
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        in >> arr[i];
    }
    in.close();
    cout << "The content of the array:  " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (mp[arr[i]] > 1)
        {
            cnt++;
        }
    }
    int most_rep = mp[arr[0]];
    int mre = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (mp[arr[i]] > most_rep)
        {
            most_rep = mp[arr[i]];
            mre = arr[i];
        }
    }
    if (cnt == 0)
    {
        cout << "There is no duplicate element in the array" << endl;
    }
    else
    {
        cout << "Total number of duplicate value = " << cnt << endl;
    }
    cout << "The most repeated element in the array: " << mre << endl;
    return 0;
}