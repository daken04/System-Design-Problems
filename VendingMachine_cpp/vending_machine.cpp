#include "vending_machine.h"

VendingMachine* VendingMachine::instance = nullptr;
std::mutex VendingMachine::lock;

VendingMachine::VendingMachine() {
    inventory = new Inventory();
    idleState = new IdleState(this);
    readyState = new ReadyState(this);
    dispenseState = new DispenseState(this);
    returnChangeState = new ReturnChangeState(this);
    currentState = idleState;
    selectedProduct = nullptr;
    totalPayment = 0.0;
}

VendingMachine* VendingMachine::getInstance() {
    std::lock_guard<std::mutex> guard(lock);
    if (!instance) {
        instance = new VendingMachine();
    }
    return instance;
}

VendingMachineState* VendingMachine::getIdleState() { return idleState; }
VendingMachineState* VendingMachine::getReadyState() { return readyState; }
VendingMachineState* VendingMachine::getDispenseState() { return dispenseState; }
VendingMachineState* VendingMachine::getReturnChangeState() { return returnChangeState; }

void VendingMachine::setState(VendingMachineState* state) {
    currentState = state;
}

void VendingMachine::selectProduct(Product* product) {
    currentState->selectProduct(product);
}

void VendingMachine::insertCoin(Coin coin) {
    currentState->insertCoin(coin);
}

void VendingMachine::insertNote(Note note) {
    currentState->insertNote(note);
}

void VendingMachine::dispenseProduct() {
    currentState->dispenseProduct();
}

void VendingMachine::returnChange() {
    currentState->returnChange();
}

void VendingMachine::addCoin(Coin coin) {
    totalPayment += static_cast<int>(coin) / 100.0;
}

void VendingMachine::addNote(Note note) {
    totalPayment += static_cast<int>(note);
}

double VendingMachine::getTotalPayment() const {
    return totalPayment;
}

void VendingMachine::resetPayment() {
    totalPayment = 0.0;
}

void VendingMachine::setSelectedProduct(Product* product) {
    selectedProduct = product;
}

Product* VendingMachine::getSelectedProduct() const {
    return selectedProduct;
}

Inventory* VendingMachine::getInventory() const {
    return inventory;
}

void VendingMachine::resetSelectedProduct() {
    selectedProduct = nullptr;
}
