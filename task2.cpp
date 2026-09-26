#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

int task2()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	double a, b, x, y, z, numerator, denominator;
	cout << "Введіть значення a, b, x, y: \n";
	cin >> a >> b >> x >> y;
	numerator = cos(pow(x, 3)) - a * sqrt(6) - cos(3 * a * b);
	denominator = pow(sin(a * sin(x) + log(y)), 2);
	z = numerator / denominator;
	cout << "Вхідні дані: ";
	cout << "a = " << a << ", " << " b = " << b << ", " << "x = " << x << ", " << "y = " << y << endl;
	cout << "Значення виразу: " << z;
	return 0;
}