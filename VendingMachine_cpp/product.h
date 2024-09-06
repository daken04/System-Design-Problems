#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
public:
    std::string name;
    double price;

    Product(std::string n, double p) : name(n), price(p) {}
};

#endif // PRODUCT_H
