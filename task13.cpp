#include <iostream>
#include <cmath>
using namespace std;

int factorial(int k) {
	if (k == 0)
		return 1;
	return k * factorial(k - 1);
}
double sqrtn(int current, int n) {
	if (current == n)
		return sqrt(factorial(current));
	return sqrt(factorial(current) + sqrtn(current + 1, n));
}

int main() {
	int n, m;
	cout << "Enter n: ";
	cin >> n;
	cout << "Enter m: ";
	cin >> m;

	double numerator = pow(3, m);

	double denominator = sqrtn(1, n);

	double result = numerator / denominator;

	cout << "Result: " << result;

	return 0;
}