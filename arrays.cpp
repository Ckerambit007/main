#include <iostream>
#include <ctime>
using namespace std;

int main() {
	srand(time(NULL));
	const int n = 10, m = 12, t = min(n, m);
	int k = 0;
	int A[n], B[m], C[t];
	cout << "A: ";
	for (int i = 0; i < n; i++) {
		A[i] = rand() % 21 - 10;
		cout << A[i] << " ";
	}

	cout << "\nB: ";
	for (int i = 0; i < m; i++) {
		B[i] = rand() % 21 - 10;
		cout << B[i] << " ";
	}

	for (int i = 0; i < n; i++) {
		bool find = false;
		for (int j = 0; j < m; j++) {
			if (A[i] == B[j]) {
				find = true;
				break;
				}
			}
		if (find) {
			bool UniqueInC = true;
			for (int l = 0; l < k; l++) {
				if (C[l] == A[i]) {
					UniqueInC = false;
					break;
				}
			}
			if (UniqueInC) {
				C[k] = A[i];
				k++;
			}
		}
	}
	cout << "\nC: ";
	for (int i = 0; i < k; i++) {
		cout << C[i] << " ";
	}
	return 0;
}
