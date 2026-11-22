#include <iostream>
#include "Dish.h"

Dish::Dish(int ownerid, double ownerprice, int ownercalories, bool ownervegeterian):
    id(ownerid > 0 ? ownerid : 1),
    price(ownerprice > 0 ? ownerprice : 0.0),
    calories((ownercalories > 0 && ownercalories < 3000) ? ownercalories : 0),
    vegeterian(ownervegeterian)
{
    std::cout << "Dish: full constructor - " << "Id: " << id << ", " << "Price: " << price << ", " << "Calories: " << calories << ", " "Vegeterian: " << vegeterian << std::endl;
}

Dish::~Dish() {
    std::cout << "Dish: " << id << std::endl;
}

int Dish::getid() const { return id; }
double Dish::getprice() const { return price; }
int Dish::getcalories() const { return calories; }
bool Dish::getvegeterian() const { return vegeterian; }

void Dish::setprice(double ownerprice) {
    if (ownerprice > 0) {
        price = ownerprice;
    }
}

bool Dish::hasSameId(const Dish& other) const {
    return id == other.id;
}

void Dish::print() const {
    std::cout << "Id: " << id << ", " << "Price: " << price << ", " << "Calories: " << calories << ", " "Vegeterian: " << vegeterian << std::endl;
}