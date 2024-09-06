#include "ready_state.h"
#include "vending_machine.h"
#include <iostream>

void ReadyState::selectProduct(Product* product) {
    std::cout << "Product already selected. Please make payment." << std::endl;
}

void ReadyState::insertCoin(Coin coin) {
    vendingMachine->addCoin(coin);
    std::cout << "Coin inserted: " << static_cast<int>(coin) / 100.0 << std::endl;
    checkPaymentStatus();
}

void ReadyState::insertNote(Note note) {
    vendingMachine->addNote(note);
    std::cout << "Note inserted: " << static_cast<int>(note) << std::endl;
    checkPaymentStatus();
}

void ReadyState::dispenseProduct() {
    std::cout << "Please make payment first." << std::endl;
}

void ReadyState::returnChange() {
    double change = vendingMachine->getTotalPayment() - vendingMachine->getSelectedProduct()->price;
    if (change > 0) {
        std::cout << "Change returned: $" << change << std::endl;
        vendingMachine->resetPayment();
    } else {
        std::cout << "No change to return." << std::endl;
    }
    vendingMachine->setState(vendingMachine->getIdleState());
}

void ReadyState::checkPaymentStatus() {
    if (vendingMachine->getTotalPayment() >= vendingMachine->getSelectedProduct()->price) {
        vendingMachine->setState(vendingMachine->getDispenseState());
    }
}
