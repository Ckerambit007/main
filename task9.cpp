
#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    srand(time(NULL));

    int n, summ = 0, k = 0;
    int* X, * Y, * Z;

    do {
        cout << "Введіть значення n: ";
        cin >> n;
    } 
    while (n < 1 || n > 20);

    X = new int[n];
    Y = new int[n];
    Z = new int[2 * n];

    cout << "X: ";
    for (int i = 0; i < n; i++) {
        *(X + i) = rand() % 11;
        cout << *(X + i) << " ";
    }

    cout << "\nY: ";
    for (int i = 0; i < n; i++) {
        *(Y + i) = rand() % 11;
        cout << *(Y + i) << " ";
    }

    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < k; j++) {
            if (*(X + i) == *(Z + j)) {
                found = true;
                break;
            }
        }
        if (!found) {
            *(Z + k) = *(X + i);
            k++;
        }
    }

    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < k; j++) {
            if (*(Y + i) == *(Z + j)) {
                found = true;
                break;
            }
        }
        if (!found) {
            *(Z + k) = *(Y + i);
            k++;
        }
    }

    cout << "\nZ: ";
    for (int i = 0; i < k; i++) {
        cout << *(Z + i) << " ";
        summ += *(Z + i);
    }
    cout << "\nСума: " << summ;

    delete[] X;
    delete[] Y;
    delete[] Z;

    return 0;
}

