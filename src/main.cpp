#include <iostream>
#include "Automata.h"

int main() {
    Automata drinkMachine;

    drinkMachine.on();
    drinkMachine.getMenu();

    drinkMachine.coin(10);
    drinkMachine.choice(1);
    drinkMachine.finish();


    return 0;
}

