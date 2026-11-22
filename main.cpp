#include <iostream>
#include "Dish.h"
#include "Table.h"
#include "Waiter.h"
using namespace std;

void printByValue(Waiter w) {
    w.print();
}

void printByConstRef(const Waiter& w) {
    w.print();
}

Waiter createobject() {
    Waiter temp(10, 12, 8, 4.9);
    return temp;
}

int main() {
    Dish owner1;
    Dish owner2(2, 3.4, 2500, true);
    Dish owner3(4);
    Dish owner4(-1, 5.5, 3125, false);

    owner1.getid();
    owner2.getprice();
    owner3.getid();
    owner4.getcalories();
    owner1.print();
    owner2.print();
    owner3.print();
    owner4.print();
    cout << endl;

    Table customer1;
    Table customer2(6, 99, 10, false);
    Table customer3(9);
    Table customer4(5, 101, 13, true);

    customer1.getid();
    customer2.getnumber();
    customer3.getid();
    customer4.getseats();
    customer1.print();
    customer2.print();
    customer3.print();
    customer4.print();
    cout << endl;

    Waiter appraiser1;
    Waiter appraiser2(4, 45, 15, 4.5);
    Waiter appraiser3(5);
    Waiter appraiser4(7, 51, 23, 4.9);

    appraiser1.getid();
    appraiser2.getexperience();
    appraiser3.gettablesServed();
    appraiser4.getrating();
    appraiser1.print();
    appraiser2.print();
    appraiser3.print();
    appraiser4.print();
    cout << endl;

    const Dish constDish(1, 250.5, 600, true);
    constDish.getid();
    constDish.getprice();
    constDish.getcalories();
    constDish.getvegeterian();
    constDish.print();
    constDish.hasSameId(owner1);
    // constDish.setprice(300.0); // C2662: "void Dish::setprice(double)": невозможно преобразовать указатель "this" из "const Dish" в "Dish &"
    cout << endl;

    const Table constTable(6, 12, 4, true);
    constTable.getid();
    constTable.print();
    constTable.hasSameId(customer1);
    // constTable.setnumber(15); // C2662: "void Table::setnumber(int)": невозможно преобразовать указатель "this" из "const Table" в "Table &"
    cout << endl;

    const Waiter constWaiter(4, 10, 8, 4.7);
    constWaiter.getid();
    constWaiter.getexperience();
    constWaiter.gettablesServed();
    constWaiter.getrating();
    constWaiter.getnote();
    constWaiter.print();
    constWaiter.hasSameId(appraiser1);
    // constWaiter.setexperience(12); // C2662: "void Waiter::setexperience(int)": невозможно преобразовать указатель "this" из "const Waiter" в "Waiter &"
    cout << endl;

    cout << "--- Передача за значенням ---" << endl;
    printByValue(appraiser2);
    cout << endl;

    cout << "--- Передача за const посиланням ---" << endl;
    printByConstRef(appraiser2);
    cout << endl;

    Waiter returnedWaiter = createobject();
    returnedWaiter.print();
    cout << endl;
    // Замість того, щоб створювати локальний об'єкт temp, копіювати його у returnedWaiter і видаляти temp, компілятор одразу сконструював об'єкт у пам'яті змінної returnedWaiter, уникнувши зайвого копіювання.

    cout << "Початок" << endl;

    {
        Table t1(1, 5, 4, true);
        Waiter w1(1, 3, 10, 4.5);
    }

    cout << "Кінець" << endl;
    cout << endl;

    Dish* owner = new Dish(4, 6.7, 2900, false);
    delete owner;

    return 0;

}