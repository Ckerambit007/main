#include <iostream>
#include "Table.h"

Table::Table() :Table{ 1, 0, 0, false } {
    std::cout << "Table: default constructor - " << "Id: " << id << ", " << "Number: " << number << ", " << "Seats: " << seats << ", " << "IsFree: " << isFree << std::endl;
}

Table::Table(int ownerid, int ownernumber, int ownerseats, bool ownerisFree) :
    id(ownerid > 0 ? ownerid : 1),
    number(ownernumber >= 1 && ownernumber <= 100 ? ownernumber : 0),
    seats(ownerseats >= 1 && ownerseats <= 12 ? ownerseats : 0),
    isFree(ownerisFree)
{
    std::cout << "Table: full constructor - " << "Id: " << id << ", " << "Number: " << number << ", " << "Seats: " << seats << ", " << "IsFree: " << isFree << std::endl;
}

Table::Table(int ownerid) :Table{ ownerid, 0, 0, false } {
    std::cout << "Table: Id constructor -  " << "Id: " << id << ", " << "Number: " << number << ", " << "Seats: " << seats << ", " << "IsFree: " << isFree << std::endl;
}

Table::~Table() {
    std::cout << "Table: " << id << std::endl;
}

int Table::getid() const { return id; }
int Table::getnumber() const { return number; }
int Table::getseats() const { return seats; }
bool Table::getisFree() const { return isFree; }

void Table::setnumber(int ownernumber) {
    if (ownernumber >= 1 && ownernumber <= 100) {
        number = ownernumber;
    }
}

bool Table::hasSameId(const Table& other) const {
    return id == other.id;
}

void Table::print() const {
    std::cout << "Id: " << id << ", " << "Number: " << number << ", " << "Seats: " << seats << ", " << "IsFree: " << isFree << std::endl;
}