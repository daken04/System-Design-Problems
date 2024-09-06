#ifndef VENDING_MACHINE_STATE_H
#define VENDING_MACHINE_STATE_H

#include "product.h"
#include "coin.h"
#include "note.h"

class VendingMachineState {
public:
    virtual ~VendingMachineState() {}
    virtual void selectProduct(Product* product) = 0;
    virtual void insertCoin(Coin coin) = 0;
    virtual void insertNote(Note note) = 0;
    virtual void dispenseProduct() = 0;
    virtual void returnChange() = 0;
};

#endif // VENDING_MACHINE_STATE_H
