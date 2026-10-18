#define _CRT_SECURE_NO_WARNINGS
//У сучасних версіях компілятора Microsoft Visual C++ такі функції, як strcpy, strcat, sprintf та деякі інші, вважаються потенційно небезпечними,
//оскільки вони не перевіряють межі буфера (може відбутися переповнення пам'яті, якщо рядок-джерело виявиться довшим за цільовий масив).
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char S[] = "I like programming for C++";
	char S1[] = "I really like to play CS2";
	cout << S << endl;
	cout << S1 << endl;
	
	const char* sep = " ,!&:;";

	char result[256] = "";

	char s1copy[256];
	strcpy(s1copy, S1);

	char* contextS = nullptr;
	//nullptr в C++ - це спеціальний літерал, який позначає нульовий покажчик (покажчик, який нікуди не вказує, тобто порожній).
	//Літерал — це зафіксоване значення певного типу даних, яке безпосередньо записане у вихідному коді програми.
	char* buf = strtok_s(S, sep, &contextS);
    //Звичайна strtok зберігає внутрішній стан у прихованій статичній змінній, через що вона не є потокобезпечною (reentrant) і ламається, якщо ви намагаєтеся паралельно розбирати два різні рядки.
	//Функція strtok_s вирішує цю проблему через додатковий параметр - контекст(context), куди сама зберігає поточну позицію сканування.
	while (buf != NULL) {
		bool find = true;
		strcpy(s1copy, S1);
		char* contextS1 = nullptr;
		char* buf1 = strtok_s(s1copy, sep, &contextS1);
		while (buf1 != NULL) {
			if (strcmp(buf, buf1) == 0) {
				find = false;
				break;
			}
			buf1 = strtok_s(NULL, sep, &contextS1);
		}
		if (find) {
			strcat(result, buf);
			strcat(result, " ");
		}
		buf = strtok_s(NULL, sep, &contextS);
	}
	cout << "Result: " << result << endl;

	return 0;
}