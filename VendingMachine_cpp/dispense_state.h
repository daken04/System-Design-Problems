#ifndef DISPENSE_STATE_H
#define DISPENSE_STATE_H

#include "vending_machine_state.h"

class VendingMachine;

class DispenseState : public VendingMachineState {
private:
    VendingMachine* vendingMachine;
public:
    DispenseState(VendingMachine* machine) : vendingMachine(machine) {}

    void selectProduct(Product* product) override;
    void insertCoin(Coin coin) override;
    void insertNote(Note note) override;
    void dispenseProduct() override;
    void returnChange() override;
};

#endif // DISPENSE_STATE_H