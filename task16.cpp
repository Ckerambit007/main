#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

struct Auto_registry {
	int id;
	char mark[32];
	int number;
	char color[32];
	int year;
	char initials[32];
	char street[32];
	int houseNumber;
};

void createList(const char* filename) {
	ofstream registry("Cars.txt");
	if (!registry.is_open()) {
		cout << "Помилка: не вдалося відкрити файл!" << endl;
		return;
	}

	int index = 1;
	char choice = 'y';

	while (choice == 'y' || choice == 'Y') {
		Auto_registry owner;
		owner.id = index;

		if (index > 1)
			cout << endl;

		cout << "Введення даних для запису №" << owner.id << endl;
		registry << owner.id << endl;

		cout << "Введіть марку авто: ";
		cin >> owner.mark;
		registry << owner.mark << endl;

		cout << "Введіть номер автомобіля: ";
		cin >> owner.number;
		registry << owner.number << endl;

		cout << "Введіть колір: ";
		cin >> owner.color;
		registry << owner.color << endl;

		cout << "Введіть рік випуску: ";
		cin >> owner.year;
		registry << owner.year << endl;

		cout << "Введіть прізвище та ініціали: ";
		cin.ignore();
		cin.getline(owner.initials, 32);
		registry << owner.initials << endl;

		cout << "Введіть вулицю: ";
		cin.getline(owner.street, 32);
		registry << owner.street << endl;

		cout << "Введіть номер будинку: ";
		cin >> owner.houseNumber;
		registry << owner.houseNumber << endl;

		registry << endl;

		index++;

		cout << "Додати ще одного власника? (y/n): ";
		cin >> choice;
	}
	registry.close();
}

void appendOwner(const char* filename) {
	int index = 0, count;
	ifstream checkFile("Cars.txt");
	if (checkFile.is_open()) {
		Auto_registry temp;
		while (checkFile >> temp.id >> temp.mark >> temp.number >> temp.color >> temp.year) {
			checkFile.ignore();
			checkFile.getline(temp.initials, 32);
			checkFile.getline(temp.street, 32);
			checkFile >> temp.houseNumber;
			index++;
		}
		checkFile.close();
	}

	count = index;

	ofstream registry("Cars.txt", ios::app);
	if (!registry.is_open()) {
		cout << "Помилка: не вдалося відкрити файл для дозапису!" << endl;
		return;
	}

	char choice = 'y';
	cout << "\nДодавання нового власника:" << endl;

	while (choice == 'y' || choice == 'Y') {
		Auto_registry owner;

		if (count > index)
			cout << endl;
		owner.id = count + 1;

		cout << "Введення даних для запису №" << owner.id << endl;
		registry << owner.id << endl;

		cout << "Введіть марку авто: ";
		cin >> owner.mark;
		registry << owner.mark << endl;

		cout << "Введіть номер автомобіля: ";
		cin >> owner.number;
		registry << owner.number << endl;

		cout << "Введіть колір: ";
		cin >> owner.color;
		registry << owner.color << endl;

		cout << "Введіть рік випуску: ";
		cin >> owner.year;
		registry << owner.year << endl;

		cout << "Введіть прізвище та ініціали: ";
		cin.ignore();
		cin.getline(owner.initials, 32);
		registry << owner.initials << endl;

		cout << "Введіть вулицю: ";
		cin.getline(owner.street, 32);
		registry << owner.street << endl;

		cout << "Введіть номер будинку: ";
		cin >> owner.houseNumber;
		registry << owner.houseNumber << endl;

		registry << endl;

		count++;

		cout << "Додати ще одного власника? (y/n): ";
		cin >> choice;
	}
	registry.close();
}

void viewList(const char* filename) {
	ifstream registry("Cars.txt");
	if (!registry.is_open()) {
		cout << "Помилка: не вдалося відкрити файл для читання!" << endl;
		return;
	}
	Auto_registry owner;
	cout << "\n--- СПИСОК ВЛАСНИКІВ АВТОМОБІЛІВ ---" << endl;

	while (registry >> owner.id >> owner.mark >> owner.number >> owner.color >> owner.year) {
		registry.ignore();
		registry.getline(owner.initials, 32);
		registry.getline(owner.street, 32);
		registry >> owner.houseNumber;

		cout << "Запис №" << owner.id << endl;
		cout << "Марка: " << owner.mark << endl;
		cout << "Номер: " << owner.number << endl;
		cout << "Колір: " << owner.color << endl;
		cout << "Рік: " << owner.year << endl;
		cout << "Власник: " << owner.initials << endl;
		cout << "Адреса: вул. " << owner.street << ", буд. " << owner.houseNumber << endl;
		cout << "-----------------------------------" << endl;
	}
	registry.close();
}

void editRecord(const char* filename) {
	Auto_registry owners[100];
	int count = 0;

	ifstream checkFile("Cars.txt");
	if (!checkFile.is_open()) {
		cout << "Помилка: не вдалося відкрити файл для редагування!" << endl;
		return;
	}

	while (checkFile >> owners[count].id >> owners[count].mark >> owners[count].number >> owners[count].color >> owners[count].year) {
		checkFile.ignore();
		checkFile.getline(owners[count].initials, 32);
		checkFile.getline(owners[count].street, 32);
		checkFile >> owners[count].houseNumber;
		count++;
	}
	checkFile.close();

	char continueEditing = 'y';
	while (continueEditing == 'y' || continueEditing == 'Y') {
		int targetId;
		cout << "Введіть номер запису (ID) для редагування (від 1 до " << count << "): ";
		cin >> targetId;

		while (targetId < 1 || targetId > count) {
			cout << "Невірний ID! Введіть число від 1 до " << count << ": ";
			cin >> targetId;
		}

		int targetIndex = targetId - 1;

		char editMore = 'y';
		while (editMore == 'y' || editMore == 'Y') {
			cout << "\nРедагування запису №" << owners[targetIndex].id << " (" << owners[targetIndex].initials << ")" << endl;
			cout << "Що саме ви хочете змінити?\n";
			cout << "1. Марку авто\n";
			cout << "2. Держ. номер\n";
			cout << "3. Колір\n";
			cout << "4. Рік випуску\n";
			cout << "5. Прізвище та ініціали власника\n";
			cout << "6. Вулицю\n";
			cout << "7. Номер будинку\n";
			cout << "Виберіть пункт (1-7): ";

			int choice;
			cin >> choice;

			switch (choice) {
			case 1:
				cout << "Введіть нову марку: ";
				cin >> owners[targetIndex].mark;
				cout << "Поле успішно змінено!\n";
				break;
			case 2:
				cout << "Введіть новий номер: ";
				cin >> owners[targetIndex].number;
				cout << "Поле успішно змінено!\n";
				break;
			case 3:
				cout << "Введіть новий колір: ";
				cin >> owners[targetIndex].color;
				cout << "Поле успішно змінено!\n";
				break;
			case 4:
				cout << "Введіть новий рік випуску: ";
				cin >> owners[targetIndex].year;
				cout << "Поле успішно змінено!\n";
				break;
			case 5:
				cout << "Введіть нові ПІБ: ";
				cin.ignore();
				cin.getline(owners[targetIndex].initials, 32);
				cout << "Поле успішно змінено!\n";
				break;
			case 6:
				cout << "Введіть нову вулицю: ";
				cin.ignore();
				cin.getline(owners[targetIndex].street, 32);
				cout << "Поле успішно змінено!\n";
				break;
			case 7:
				cout << "Введіть новий номер будинку: ";
				cin >> owners[targetIndex].houseNumber;
				cout << "Поле успішно змінено!\n";
				break;
			default:
				cout << "Невірний вибір пункту!\n";
				break;
			}

			cout << "Бажаєте змінити ще щось у цього ж власника? (y/n): ";
			cin >> editMore;
		}

		cout << "Бажаєте відредагувати іншого власника? (y/n): ";
		cin >> continueEditing;
	}

	ofstream registry("Cars.txt", ios::out);
	for (int i = 0; i < count; i++) {
		registry << owners[i].id << endl;
		registry << owners[i].mark << endl;
		registry << owners[i].number << endl;
		registry << owners[i].color << endl;
		registry << owners[i].year << endl;
		registry << owners[i].initials << endl;
		registry << owners[i].street << endl;
		registry << owners[i].houseNumber << endl;
	}
	registry.close();

	cout << "Файл успішно оновлено та збережено!\n";
}

void printFilteredAndSorted(const char* filename, const char* targetMark) {
	Auto_registry owners[100];
	int count = 0;

	ifstream fileIn("Cars.txt");
	if (!fileIn.is_open()) {
		cout << "Помилка: не вдалося відкрити файл!\n";
		return;
	}

	while (fileIn >> owners[count].id >> owners[count].mark >> owners[count].number >> owners[count].color >> owners[count].year) {
		fileIn.ignore();
		fileIn.getline(owners[count].initials, 32);
		fileIn.getline(owners[count].street, 32);
		fileIn >> owners[count].houseNumber;
		count++;
	}
	fileIn.close();

	Auto_registry filtered[100];
	int filteredCount = 0;

	for (int i = 0; i < count; i++) {
		bool isTargetMark = (strcmp(owners[i].mark, targetMark) == 0);

		int num = owners[i].number;
		while (num >= 100) {
			num /= 10;
		}

		bool startsWith55 = (num == 55);

		if (isTargetMark && startsWith55) {
			filtered[filteredCount] = owners[i];
			filteredCount++;
		}
	}

	if (filteredCount == 0) {
		cout << "Не знайдено жодного власника для марки " << targetMark << ", чий номер починається з '55'.";
		return;
	}

	for (int i = 0; i < filteredCount - 1; i++) {
		for (int j = i + 1; j < filteredCount; j++) {
			if (strcmp(filtered[i].initials, filtered[j].initials) > 0) {
				swap(filtered[i], filtered[j]);
			}
		}
	}

	cout << "\n--- СПИСОК ВЛАСНИКІВ (Марка: " << targetMark << ", номери на '55', за алфавітом) ---\n";
	for (int i = 0; i < filteredCount; i++) {
		cout << "Запис №" << filtered[i].id << endl;
		cout << "Марка: " << filtered[i].mark << endl;
		cout << "Номер: " << filtered[i].number << endl;
		cout << "Колір: " << filtered[i].color << endl;
		cout << "Рік: " << filtered[i].year << endl;
		cout << "Власник: " << filtered[i].initials << endl;
		cout << "Адреса: вул. " << filtered[i].street << ", буд. " << filtered[i].houseNumber << endl;
		cout << "--------------------------------------------------\n";
	}
}

int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	int k;
	char choice = 'y';

	createList("Cars.txt");

	while (choice == 'y' || choice == 'Y') {
		cout << "\nЩо ви хочете робити?" << endl;
		cout << "1. Додати нові записи" << endl;
		cout << "2. Переглядати список власників автомобілів" << endl;
		cout << "3. Внести зміни у запис про власника автомобіля" << endl;
		cout << "4. Вивести за алфавітним порядком список власників заданої марки, номер яких починається з '55'" << endl;
		cout << "\nВведіть номер запиту: ";
		cin >> k;

		if (k == 1) {
			appendOwner("Cars.txt");
		}
		else if (k == 2) {
			viewList("Cars.txt");
		}
		else if (k == 3) {
			editRecord("Cars.txt");
		}
		else if (k == 4) {
			char searchMark[32];
			cout << "Введіть марку авто для пошуку: ";
			cin >> searchMark;
			printFilteredAndSorted("Cars.txt", searchMark);
		}
		else {
			cout << "Невірний вибір пункту меню!" << endl;
		}

		cout << "\nПовернутися до можливих операцій (y/n): ";
		cin >> choice;
	}

	return 0;
}
