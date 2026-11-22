#pragma once
class Table {
private:
    int id;
    int number;
    int seats;
    bool isFree;
public:
    Table();
    Table(int ownerid, int ownernumber, int ownerseats, bool ownerisFree);
    Table(int ownerid);
    ~Table();
    int getid() const;
    int getnumber() const;
    int getseats() const;
    bool getisFree() const;

    void setnumber(int ownernumber);
    bool hasSameId(const Table& other) const;

    void print() const;
};