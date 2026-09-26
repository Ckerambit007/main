#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;

int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	double x, a, e, dod, sum = 0, coskx = 1, a4k = 1, kfact = 1, k = 0;
	do {
		cout << "Input e: ";
		cin >> e;
	} while (e <= 0);

	do {
		cout << "Input x :";
		cin >> x;
	} while (x == 0);

	do {
		cout << "Input a :";
		cin >> a;
	} while (a == 0);
	
	do {
		k++;
		coskx *= cos(x);
		a4k *= a * a * a * a;
		kfact *= k;
		dod = coskx / (a4k + kfact);
		sum += dod;
		cout << k << ". " << dod << endl;

	} 
	while (abs(dod) >= e);
	cout << "it was " << k << " addends" << endl;
	cout << "Sum = " << sum << endl;
	return 0;
}