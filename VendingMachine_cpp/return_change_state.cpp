#include "return_change_state.h"
#include "vending_machine.h"
#include <iostream>

void ReturnChangeState::selectProduct(Product* product) {
    std::cout << "Please collect the change first." << std::endl;
}

void ReturnChangeState::insertCoin(Coin coin) {
    std::cout << "Please collect the change first." << std::endl;
}

void ReturnChangeState::insertNote(Note note) {
    std::cout << "Please collect the change first." << std::endl;
}

void ReturnChangeState::dispenseProduct() {
    std::cout << "Product already dispensed. Please collect the change." << std::endl;
}

void ReturnChangeState::returnChange() {
    double change = vendingMachine->getTotalPayment() - vendingMachine->getSelectedProduct()->price;
    if (change > 0) {
        std::cout << "Change returned: $" << change << std::endl;
        vendingMachine->resetPayment();
    } else {
        std::cout << "No change to return." << std::endl;
    }
    vendingMachine->resetSelectedProduct();
    vendingMachine->setState(vendingMachine->getIdleState());
}
