#include <iostream>
using namespace std;


class Dish {
private:
    int id;
    double price;
    int calories;
    bool vegeterian;
public:
    Dish() {
        id = 1;
        price = 0.0;
        calories = 0;
        vegeterian = false;
        cout << "Dish: default constructor - " << "Id: " << id << ", " << "Price: " << price << ", " << "Calories: " << calories << ", " "Vegeterian: " << vegeterian << endl;
    }

    Dish(int ownerid, double ownerprice, int ownercalories, bool ownervegeterian) {
        if (ownerid > 0)
            id = ownerid;
        else
            id = 1;

        if (ownerprice > 0)
            price = ownerprice;
        else
            price = 0.0;

        if (ownercalories > 0 && ownercalories < 3000)
            calories = ownercalories;
        else
            calories = 0;

        vegeterian = ownervegeterian;

        cout << "Dish: full constructor - " << "Id: " << id << ", " << "Price: " << price << ", " << "Calories: " << calories << ", " "Vegeterian: " << vegeterian << endl;
    }
    Dish(int ownerid) {
        if (ownerid > 0)
            id = ownerid;
        else
            id = 1;
        price = 0.0;
        calories = 0;
        vegeterian = false;

        cout << "Dish: Id constructor - " << "Id: " << id << ", " << "Price: " << price << ", " << "Calories: " << calories << ", " "Vegeterian: " << vegeterian << endl;
    }

    ~Dish() {
        cout << "Dish: " << id << endl;
    }

    int getid() { return id; }
    double getprice() { return price; }
    int getcalories() { return calories; }
    bool getvegeterian() { return vegeterian; }

    void print() {
        cout << "Id: " << id << ", " << "Price: " << price << ", " << "Calories: " << calories << ", " "Vegeterian: " << vegeterian << endl;
    }
};

class Table {
private:
    int id;
    int number;
    int seats;
    bool isFree;
public:
    Table() {
        id = 1;
        number = 1;
        seats = 2;
        isFree = true;
        cout << "Table: default constructor - " << "Id: " << id << ", " << "Number: " << number << ", " << "Seats: " << seats << ", " << "IsFree: " << isFree << endl;
    }

    Table(int ownerid, int ownernumber, int ownerseats, bool ownerisFree) {
        if (ownerid > 0)
            id = ownerid;
        else
            id = 1;

        if (ownernumber >= 1 && ownernumber <= 100)
            number = ownernumber;
        else
            number = 1;

        if (ownerseats >= 1 && ownerseats <= 12)
            seats = ownerseats;
        else
            seats = 2;

        isFree = ownerisFree;

        cout << "Table: full constructor - " << "Id: " << id << ", " << "Number: " << number << ", " << "Seats: " << seats << ", " << "IsFree: " << isFree << endl;
    }

    Table(int ownerid) {
        if (ownerid > 0)
            id = ownerid;
        else
            id = 1;
        number = 1;
        seats = 2;
        isFree = true;

        cout << "Table: Id constructor -  " << "Id: " << id << ", " << "Number: " << number << ", " << "Seats: " << seats << ", " << "IsFree: " << isFree << endl;
    }

    ~Table() {
        cout << "Table: " << id << endl;
    }

    int getid() { return id; }
    int getnumber() { return number; }
    int getseats() { return seats; }
    bool getisFree() { return isFree; }

    void print() {
        cout << "Id: " << id << ", " << "Number: " << number << ", " << "Seats: " << seats << ", " << "IsFree: " << isFree << endl;
    }
};

class Waiter {
private:
    int id;
    int experience;
    int tablesServed;
    double rating;
public:
    Waiter() {
        id = 1;
        experience = 0;
        tablesServed = 0;
        rating = 0.0;
        cout << "Waiter: default constructor - " << "Id: " << id << ", " << "Experience: " << experience << ", " << "TablesServed: " << tablesServed << ", " << "Rating: " << rating << endl;
    }

    Waiter(int ownerid, int ownerexperience, int ownertablesServed, double ownerrating) {
        if (ownerid > 0)
            id = ownerid;
        else
            id = 1;

        if (ownerexperience >= 0 && ownerexperience <= 50)
            experience = ownerexperience;
        else
            experience = 0;

        if (ownertablesServed >= 0 && ownertablesServed <= 20)
            tablesServed = ownertablesServed;
        else
            tablesServed = 0;

        if (ownerrating >= 0.0 && ownerrating <= 5.0)
            rating = ownerrating;
        else
            rating = 0.0;

        cout << "Waiter: full constructor - " << "Id: " << id << ", " << "Experience: " << experience << ", " << "TablesServed: " << tablesServed << ", " << "Rating: " << rating << endl;
    }

    Waiter(int ownerid) {
        if (ownerid > 0)
            id = ownerid;
        else
            id = 1;
        experience = 0;
        tablesServed = 0;
        rating = 0.0;

        cout << "Waiter: Id constructor - " << "Id: " << id << ", " << "Experience: " << experience << ", " << "TablesServed: " << tablesServed << ", " << "Rating: " << rating << endl;
    }

    ~Waiter() {
        cout << "Waiter: " << id << endl;
    }

    int getid() { return id; }
    int getexperience() { return experience; }
    int gettablesServed() { return tablesServed; }
    double getrating() { return rating; }

    void print() {
        cout << "Id: " << id << ", " << "Experience: " << experience << ", " << "TablesServed: " << tablesServed << ", " << "Rating: " << rating << endl;
    }
};

int main() {
    Dish owner1;
    Dish owner2(2, 3.4, 2500, true);
    Dish owner3(4);
    Dish owner4(-1, 5.5, 3125, false);
    cout << endl;

    Table customer1;
    Table customer2(6, 99, 10, false);
    Table customer3(9);
    Table customer4(5, 101, 13, true);
    cout << endl;

    Waiter appraiser1;
    Waiter appraiser2(4, 45, 15, 4.5);
    Waiter appraiser3(5);
    Waiter appraiser4(7, 51, 23, 4.9);
    cout << endl;

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