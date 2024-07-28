#include <iostream>
using namespace std;
void EXCHANGE(int &p, int &q)
{
    int temp = p;
    p = q;
    q = temp;
}

void ROTATE_RIGHT(int arr[], int p2)
{
    if (p2 <= 1)
        return; 
    for (int i = p2 - 1; i > 0; i--)
    {
        EXCHANGE(arr[i], arr[i - 1]);
    }
}

int main()
{
    int n;
    cout << "Enter the size of an array: " << endl;
    cin >> n;
    int arr[n];

    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int p2;
    cout << "Enter the number of elements you want to rotate: " << endl;
    cin >> p2;

    cout << "Before Rotate: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    ROTATE_RIGHT(arr, p2);
    cout << "After Rotate: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
