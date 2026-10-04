#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int main() {
	const int n = 7;
	int first = -1, last, k = 0, sum = 0;
	int A[n][n];
	long long X[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			A[i][j] = rand() % 5 -2;
			cout << setw(4) << A[i][j];
		}
		cout << endl;
	}

	for (int i = 0; i < n; i++) {
		first = -1;
		bool npos = true;
		for (int j = 0; j < n; j++) {
			if (A[i][j] > 0) {
				first = j;
				npos = false;
				break;
			}
		}

		if (npos) {
			X[k] = first;
			k++;
			continue;
		}

		else {
			for (int l = n - 1; l >= 0; l--) {
				if (A[i][l] > 0) {
					last = l;
					break;
				}
			}

			if (last == first) {
				X[k] = -1;
				k++;
				continue;
			}

			else if (last == first + 1) {
				X[k] = -1;
				k++;
				continue;
			}

			else {
				for (int r = first + 1; r < last; r++) {
					sum += abs(A[i][r]);
				}
				X[k] = sum;
				sum = 0;
				k++;
			}
		}
	}

	cout << "\nX: ";
	for (int i = 0; i < n; i++) {
		cout << X[i] << " ";
	}

	return 0;
}

