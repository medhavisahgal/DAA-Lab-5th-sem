#include <iostream>
#include <fstream>
using namespace std;
int gcd_fun(int a, int b)
{
    if (b == 0)
        return a;
    return gcd_fun(b, a % b);
}
int main(int argc, char *argv[])
{
    string inpath;
    string outpath;
    if (argc != 3)
    {
        cout << "USAGE: ./a.exe {input file} {output file}" << endl;
        return 0;
    }
    else
    {
        inpath = argv[1];
        outpath = argv[2];
    }
    int n;
    cout << "Number pairs you want to read from the input file" << endl;
    cin >> n;
    ifstream in(inpath);
    ofstream out(outpath);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        in >> a;
        in >> b;
        int gcd = gcd_fun(a, b);
        string final = "The GCD of " + to_string(a) + " and " + to_string(b) + " is " + to_string(gcd);
        cout << final << endl;
        out << final << endl;
    }
    in.close();
    out.close();
    return 0;
}