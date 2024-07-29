#include <iostream>
#include <fstream>
using namespace std;
void dtob(int num, string &bi)
{
    if (num == 0)
        return;
    bi += to_string(num & 1);
    dtob(num >> 1, bi);
}
int main()
{
    int n;
    cout << "How many numbers you want to read for the disc file" << endl;
    cin >> n;
    ifstream in("inDec.dat");
    int a[n];
    for (int i = 0; i < n; i++)
    {
        in >> a[i];
    }
    in.close();
    ofstream out("outBin.dat");
    for (int x : a)
    {
        string bi = "";
        dtob(x, bi);
        out << bi << endl;
    }
    out.close();
    cout << "Binary form of first " << n << " decimals have been saved in output1.dat";
    return 0;
}