#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	double a, t, v0, s;
	cout << "Введіть значення прискорення (в м/с^2): ";
	cin >> a;
	cout << "Введіть значення часу (в секундах): ";
	cin >> t;
	cout << "Введіть значення початкової швидкості (в м/с): ";
	cin >> v0;
	s = v0 * t + (a * pow(t, 2)) / 2;
	cout << "Вхідні дані: ";
	cout << "a = " << a << " м/с^2" ", " << " t = " << t << "с" ", " << " v0 = " << v0 << " м/с" << endl;
	cout << "Значення переміщення (в метрах): " << s << endl;
	return 0;

}
