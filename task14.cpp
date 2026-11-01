#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

struct Marshrut {
    int N;
    char Poch[32];
    char Kin[32];
};

void printRoutes(const Marshrut *arr, int size, int nomer) {
    cout << "Маршрут №" << arr[nomer].N << ", Відправлення: " << arr[nomer].Poch << ", Призначення: " << arr[nomer].Kin << endl;
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    const int k = 4;
    Marshrut zaps[k];

    for (int i = 0; i < k; i++) {
        cout << "Введіть номер маршруту, пункт відправлення та пункт призначення:" << endl;
        cin >> zaps[i].N;
        cin.ignore();

        //Коли ви вводите число через cin >> nomer і натискаєте клавішу Enter, у буфері введення залишається саме число, а відразу після нього символ нового рядка (\n).
        //Якщо після цього відразу викликати cin.getline(), він не буде чекати введення від користувача, а миттєво зчитає цей символ,
        //що залишився в буфері \n. В результаті рядок залишиться порожнім, а програма проскочить крок введення.

        cin.getline(zaps[i].Poch, 32);
        cin.getline(zaps[i].Kin, 32);
    }

    char vved[32];
    cout << "Введіть пункт для пошуку: ";
    cin.getline(vved, 32);

    int fine = 0;
    for (int i = 0; i < k; i++) {
        if (strcmp(vved, zaps[i].Poch) == 0) {
            printRoutes(zaps, k, i);
            fine++;
            continue;
        }
        if (strcmp(vved, zaps[i].Kin) == 0) {
            printRoutes(zaps, k, i);
            fine++;
            continue;
        }
    }
    if (fine == 0)
        cout << "Співпадінь не знайдено";
    else
        cout << "Знайдено " << fine << " співпадінь";

    return 0;
}