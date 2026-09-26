#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;

int main()
{
    double x, y, z;
    bool p, q, v;
    cout << "Введіть значення x, y, z: ";
    cin >> x >> y >> z;
    cout << "Введіть значення p, q: ";
    cin >> p >> q;
    if (min(min(abs(x), abs(y)), abs(z)) > x + y + z)
    {
        v = p;
    }
    else
    {
        v = q;
    }
    cout << "V = " << v;

    return 0;



}
