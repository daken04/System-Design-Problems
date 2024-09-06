#include "dispense_state.h"
#include "vending_machine.h"
#include <iostream>

void DispenseState::selectProduct(Product* product) {
    std::cout << "Product already selected. Please collect the dispensed product." << std::endl;
}

void DispenseState::insertCoin(Coin coin) {
    std::cout << "Payment already made. Please collect the dispensed product." << std::endl;
}

void DispenseState::insertNote(Note note) {
    std::cout << "Payment already made. Please collect the dispensed product." << std::endl;
}

void DispenseState::dispenseProduct() {
    vendingMachine->setState(vendingMachine->getReadyState()); // Set back to ready state after dispensing
    Product* product = vendingMachine->getSelectedProduct();
    vendingMachine->getInventory()->updateQuantity(product, vendingMachine->getInventory()->getQuantity(product) - 1);
    
    std::cout << "Product dispensed: " << product->name << std::endl;
    vendingMachine->setState(vendingMachine->getReturnChangeState()); // Move to return change state
}

void DispenseState::returnChange() {
    std::cout << "Please collect the dispensed product first." << std::endl;
}
