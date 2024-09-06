#ifndef READY_STATE_H
#define READY_STATE_H
#include <bits/stdc++.h>
using namespace std;

#include "vending_machine_state.h"
#include "vending_machine.h"


class VendingMachine;

class ReadyState : public VendingMachineState {
private:
    VendingMachine* vendingMachine;
public:
    ReadyState(VendingMachine* machine) : vendingMachine(machine) {}

    void selectProduct(Product* product) override ;

    void insertCoin(Coin coin) override;

    void insertNote(Note note) override;

    void dispenseProduct() override;

    void returnChange() override;

    void checkPaymentStatus();
};

#endif // READY_STATE_H
