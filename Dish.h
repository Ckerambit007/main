#ifndef DISH_H
#define DISH_H

class Dish {
private:
    const int id;
    double price;
    int calories;
    bool vegeterian;
public:
    Dish(int id = 1, double price = 0.0, int calories = 0, bool vegeterian = false );
    ~Dish();
    int getid() const;
    double getprice() const;
    int getcalories() const;
    bool getvegeterian() const;

    void setprice(double ownerprice);
    bool hasSameId(const Dish& other) const;

    void print() const;

};

#endif