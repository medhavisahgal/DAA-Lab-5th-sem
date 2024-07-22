#include <iostream>
using namespace std;

void EXCHANGE(int &p, int &q)
{
    int temp = p;
    p = q;
    q = temp;
}

void ROTATE_RIGHT(int *p1, int p2)
{
    if (p2 <= 1)
        return;

    for (int i = p2 - 1; i > 0; i--)
    {
        EXCHANGE(p1[i], p1[i - 1]);
    }
}

int main()
{
    int N;
    cout << "Enter the size of the array: ";
    cin >> N;
    int A[N];
    for(int i=0;i<N;i++){
        A[i]=rand();
    }
    int p2;
    cout << "Enter the number of elements to rotate: ";
    cin >> p2;

    cout << "Before ROTATE: ";
    for (int i = 0; i < N; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    ROTATE_RIGHT(A, p2);

    cout << "After ROTATE: ";
    for (int i = 0; i < N; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
