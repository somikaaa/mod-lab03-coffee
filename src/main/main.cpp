#include <iostream>
#include "Automata.h"

int main() {
    Automata vendingMachine;

    vendingMachine.on();

    vendingMachine.choice(0);

    vendingMachine.check();

    vendingMachine.coin(100);

    vendingMachine.check();

    vendingMachine.cook();

    vendingMachine.finish();

    return 0;
}
