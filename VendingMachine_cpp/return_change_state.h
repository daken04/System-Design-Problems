#ifndef RETURN_CHANGE_STATE_H
#define RETURN_CHANGE_STATE_H
#include <bits/stdc++.h>
using namespace std;

#include "vending_machine_state.h"
#include "vending_machine.h"


class VendingMachine;

class ReturnChangeState : public VendingMachineState {
private:
    VendingMachine* vendingMachine;
public:
    ReturnChangeState(VendingMachine* machine) : vendingMachine(machine) {}

    void selectProduct(Product* product) override;

    void insertCoin(Coin coin) override ;

    void insertNote(Note note) override;

    void dispenseProduct() override;

    void returnChange() override;
};

#endif // RETURN_CHANGE_STATE_H
