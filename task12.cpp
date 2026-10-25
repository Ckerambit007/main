#include <iostream>
#include <ctime>
using namespace std;
void dis(int* A, const int n1, int* B, const int n2, int* C, int &realsize) {
	realsize = 0;
	for (int i = 0; i < n1; i++) {
		bool find = true;
		for (int j = 0; j < n2; j++) {
			if (A[i] == B[j]) {
				find = false;
				break;
			}
		}
		if (find) {
			C[realsize] = A[i];
			realsize++;
		}
	}
	for (int i = 0; i < n2; i++) {
		bool find = true;
		for (int j = 0; j < n1; j++) {
			if (B[i] == A[j]) {
				find = false;
				break;
			}
		}
		if (find) {
			C[realsize] = B[i];
			realsize++;
		}
	}
}

int findMin(const int* C, int n) {
	int minVal = C[0];
	for (int i = 1; i < n; i++) {
		if (C[i] < minVal)
			minVal = C[i];
	}
	return minVal;
}

int main() {
	srand(time(NULL));
	const int n = 5, m = 5;
	const int s = n + m;
	int realsize = 0;
	int A[n], B[m], C[s];
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

	dis(A, n, B, m, C, realsize);

	cout << "\nC: ";
	for (int i = 0; i < realsize; i++) {
		cout << C[i] << " ";
	}

	int minimum = findMin(C, realsize);
	cout << "\nMinimum value: " << minimum;

	return 0;
}
