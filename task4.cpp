#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;

int main()
{
	double x, y, z;
	int k;

	cout << "Введіть значення x, y, z, k: ";
	cin >> x >> y >> z;
	cout << "Введіть значення k: ";
	cin >> k;
	switch (k) {
	case 1:
	{
		cout << "Результат: " << pow(k, 2) * x + max(y, z);
		break;
	}
	case 2:
	{
		cout << "Результат: " << (y / pow(k, 2)) + max(x, z);
		break;
	}
	case 3:
	{
		cout << "Результат: " << z + (k / min(x, y)) + max(max(x, y), z);
		break;
	}
	default:
		cout << sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	}

	return 0;
}
