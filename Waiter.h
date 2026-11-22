#ifndef WAITER_H
#define WAITER_H

class Waiter {
private:
	const int id;
	int experience;
	int tablesServed;
	double rating;
	int* note;
public:
	Waiter();
	Waiter(int ownerid, int ownerexperience, int ownertablesServed, double ownerrating);
	Waiter(int ownerid);
	Waiter(const Waiter& other);
	~Waiter();
	int getid() const;
	int getexperience() const;
	int gettablesServed() const;
	double getrating() const;

	void setexperience(int ownerexperience);
	void setNote(int value);
	bool hasSameId(const Waiter& other) const;

	int getnote() const;
	void print() const;
};

#endif