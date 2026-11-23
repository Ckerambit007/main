#include <iostream>
#include "Waiter.h"

Waiter::Waiter() : id{ 1 }, experience{ 0 }, tablesServed{ 0 }, rating{ 0.0 }, note{ new int(0) } {
	std::cout << "Waiter: default constructor - " << "Id: " << id << ", " << "Experience: " << experience << ", " << "TablesServed: " << tablesServed << ", " << "Rating: " << rating << ", " << "Note: " << *note << std::endl;
}

Waiter::Waiter(int ownerid, int ownerexperience, int ownertablesServed, double ownerrating) :
	id(ownerid > 0 ? ownerid : 1),
	experience((ownerexperience >= 0 && ownerexperience <= 50) ? ownerexperience : 0),
	tablesServed((ownertablesServed >= 0 && ownertablesServed <= 20) ? ownertablesServed : 0),
	rating((ownerrating >= 0.0 && ownerrating <= 5.0) ? ownerrating : 0.0),
	note(new int(0))
{
	std::cout << "Waiter: full constructor - " << "Id: " << id << ", " << "Experience: " << experience << ", " << "TablesServed: " << tablesServed << ", " << "Rating: " << rating << ", " << "Note: " << *note << std::endl;
}

Waiter::Waiter(int ownerid) : id(ownerid > 0 ? ownerid : 1), experience{ 0 }, tablesServed{ 0 }, rating{ 0.0 }, note{ new int(0) } {
	std::cout << "Waiter: Id constructor - " << "Id: " << id << ", " << "Experience: " << experience << ", " << "TablesServed: " << tablesServed << ", " << "Rating: " << rating << ", " << "Note: " << *note << std::endl;
}

Waiter::Waiter(const Waiter& other) :
	id(other.id),
	experience(other.experience),
	tablesServed(other.tablesServed),
	rating(other.rating),
	note(new int(*other.note))
{
	std::cout << "Waiter: Copy constructor - " << "Id: " << id << ", " << "Note: " << *note << std::endl;
}

Waiter::~Waiter() {
	std::cout << "Waiter: " << id << std::endl;
	delete note;
}

int Waiter::getid() const { return id; }
int Waiter::getexperience() const { return experience; }
int Waiter::gettablesServed() const { return tablesServed; }
double Waiter::getrating() const { return rating; }
int Waiter::getnote() const { return *note; }

void Waiter::setexperience(int ownerexperience) {
	if (ownerexperience >= 0 && ownerexperience <= 50) {
		experience = ownerexperience;
	}
}

void Waiter::setNote(int value) {
	*note = value;
}

bool Waiter::hasSameId(const Waiter& other) const {
	return id == other.id;
}

void Waiter::print() const {
	std::cout << "Id: " << id << ", " << "Experience: " << experience << ", " << "TablesServed: " << tablesServed << ", " << "Rating: " << rating << ", " << "Note: " << *note << std::endl;
}
