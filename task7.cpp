#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;

int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	srand(time(NULL));
	const int n = 20;
	int A[n], first = -1, last = -1;
	long long m = 1;

	cout << "A: ";
	for (int i = 0; i < n; i++) {
		A[i] = rand() % 21 - 10;
		cout << A[i] << " ";
	}

	for (int i = 0; i < n; i++) {
		if (A[i] < 0) {
			first = i;
			break;
		}
	}

	for (int j = n - 1; j >= 0; j--) {
		if (A[j] < 0) {
			last = j;
			break;
		}
	}
	if (first == -1) {
		cout << "\nВід’ємних чисел немає";
	}
	else if (first == last) {
		cout << "\nТільки від'ємне число: A[" << first << "] = " << A[first];
	}
	else if (last == first + 1) {
		cout << "\nВід'ємні числа стоять поряд";
	}
	else{
		for (int k = first + 1; k < last; k++)
			m *= A[k];
		cout << "\nk: ";
		for (int i = first + 1; i < last; i++)
			cout << A[i] << " ";
		cout << "\nm: " << m;
	}
	return 0;
}
