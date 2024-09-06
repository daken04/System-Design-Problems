#ifndef IDLE_STATE_H
#define IDLE_STATE_H
#include <bits/stdc++.h>
using namespace std;

#include "vending_machine_state.h"
#include "inventory.h"
#include "vending_machine.h"

class VendingMachine;

class IdleState : public VendingMachineState {
private:
    VendingMachine* vendingMachine;
public:
    IdleState(VendingMachine* machine) : vendingMachine(machine) {}

    void selectProduct(Product* product) override;

    void insertCoin(Coin coin) override;

    void insertNote(Note note) override ;

    void dispenseProduct() override;

    void returnChange() override;
};

#endif // IDLE_STATE_H
