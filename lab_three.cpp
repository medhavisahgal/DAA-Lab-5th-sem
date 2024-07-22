#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = rand();
    }
    cout << "original array is" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[a[i]]++;
    }
    int td = 0;
    int mr = m[a[0]];
    for (auto i : m)
    {
        if (i.second > 1)
        {
            td++;
        }
        if (i.second > mr)
        {
            mr = i.second;
        }
    }
    cout << "Total duplicate elements are " << td << endl;
    cout << "Maximum frequency of an element is " << mr << endl;
}