#ifndef INVENTORY_H
#define INVENTORY_H

#include <unordered_map>
#include "product.h"

class Inventory {
private:
    std::unordered_map<Product*, int> products;
public:
    void addProduct(Product* product, int quantity) {
        products[product] = quantity;
    }

    void removeProduct(Product* product) {
        products.erase(product);
    }

    void updateQuantity(Product* product, int quantity) {
        products[product] = quantity;
    }

    int getQuantity(Product* product) {
        return products[product];
    }

    bool isAvailable(Product* product) {
        return products.find(product) != products.end() && products[product] > 0;
    }
};

#endif // INVENTORY_H
