#include "idle_state.h"
#include "vending_machine.h"
#include <iostream>

void IdleState::selectProduct(Product* product) {
    if (vendingMachine->getInventory()->isAvailable(product)) {
        vendingMachine->setSelectedProduct(product);
        vendingMachine->setState(vendingMachine->getReadyState());
        std::cout << "Product selected: " << product->name << std::endl;
    } else {
        std::cout << "Product not available: " << product->name << std::endl;
    }
}

void IdleState::insertCoin(Coin coin) {
    std::cout << "Please select a product first." << std::endl;
}

void IdleState::insertNote(Note note) {
    std::cout << "Please select a product first." << std::endl;
}

void IdleState::dispenseProduct() {
    std::cout << "Please select a product and make payment." << std::endl;
}

void IdleState::returnChange() {
    std::cout << "No change to return." << std::endl;
}
