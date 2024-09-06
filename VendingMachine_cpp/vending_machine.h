#ifndef VENDING_MACHINE_H
#define VENDING_MACHINE_H

#include <mutex>
#include "idle_state.h"
#include "ready_state.h"
#include "dispense_state.h"
#include "return_change_state.h"
#include "inventory.h"

class VendingMachine {
private:
    static VendingMachine* instance;
    static std::mutex lock;

    Inventory* inventory;
    VendingMachineState* idleState;
    VendingMachineState* readyState;
    VendingMachineState* dispenseState;
    VendingMachineState* returnChangeState;

    VendingMachineState* currentState;
    Product* selectedProduct;
    double totalPayment;

    VendingMachine(); // Constructor is now declared but will be defined in vending_machine.cpp

public:
    static VendingMachine* getInstance();

    VendingMachineState* getIdleState();
    VendingMachineState* getReadyState();
    VendingMachineState* getDispenseState();
    VendingMachineState* getReturnChangeState();

    void setState(VendingMachineState* state);

    void selectProduct(Product* product);

    void insertCoin(Coin coin);

    void insertNote(Note note);

    void dispenseProduct();

    void returnChange();

    void addCoin(Coin coin);

    void addNote(Note note);

    double getTotalPayment() const;

    void resetPayment();

    void setSelectedProduct(Product* product);

    Product* getSelectedProduct() const;

    Inventory* getInventory() const;

    void resetSelectedProduct();
};

#endif // VENDING_MACHINE_H
