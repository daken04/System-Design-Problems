#include "vending_machine.h"
#include "coin.h"
#include "note.h"
#include "product.h"

int main() {
    VendingMachine* vendingMachine = VendingMachine::getInstance();

    // Add products to the inventory
    Product coke("Coke", 1.5);
    Product pepsi("Pepsi", 1.5);
    Product water("Water", 1.0);

    vendingMachine->getInventory()->addProduct(&coke, 5);
    vendingMachine->getInventory()->addProduct(&pepsi, 3);
    vendingMachine->getInventory()->addProduct(&water, 2);

    // Select a product
    vendingMachine->selectProduct(&coke);

    // Insert coins
    vendingMachine->insertCoin(Coin::QUARTER);
    vendingMachine->insertCoin(Coin::QUARTER);
    vendingMachine->insertCoin(Coin::QUARTER);
    vendingMachine->insertCoin(Coin::QUARTER);

    // Insert a note
    vendingMachine->insertNote(Note::FIVE);

    // Dispense the product
    vendingMachine->dispenseProduct();

    // Return change
    vendingMachine->returnChange();

    // Select another product
    vendingMachine->selectProduct(&pepsi);

    // Insert insufficient payment
    vendingMachine->insertCoin(Coin::QUARTER);

    // Try to dispense the product
    vendingMachine->dispenseProduct();

    // Insert more coins
    vendingMachine->insertCoin(Coin::QUARTER);
    vendingMachine->insertCoin(Coin::QUARTER);
    vendingMachine->insertCoin(Coin::QUARTER);
    vendingMachine->insertCoin(Coin::QUARTER);

    // Dispense the product
    vendingMachine->dispenseProduct();

    // Return change
    vendingMachine->returnChange();

    return 0;
}
