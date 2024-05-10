// Copyright 2022 UNN-IASR
#include "Automata.h"

using namespace std;
Automata::Automata() : cash(0.0), state(STATES::OFF), choiceIndex(-1) {
    menu = { "Coffee",
        "Tea",
        "Syrup",
        "Sugar",
        "Milk",
        "Chocolate"};
    prices = { 5.0,
        3.0,
        2.0,
        1.0,
        1.5,
        4.0 };
}

// Включение автомата
void Automata::on() {
    if (state == STATES::OFF) {
        state = STATES::WAIT;
        cout << "The drinks machine is on." << endl;
    }
}

// Выключение автомата
void Automata::off() {
    if (state == STATES::WAIT) {
        state = STATES::OFF;
        cout << "The drinks machine is off." << endl;
    }
}

// Добавление средств на счет
void Automata::coin(double amount) {
    if (state == STATES::WAIT || state == STATES::ACCEPT) {
        cout << "Please deposit the money." << endl;
        cash += amount;
        state = STATES::ACCEPT;
        cout << "The money was deposited successfully." << endl;
        cout << "The balance: " << cash << endl;
    }
}

void Automata::getMenu() {
    cout << "Choose a drink" << endl;
    cout << "Menu: " << endl;
    for (size_t i = 0; i < menu.size(); ++i) {
        cout << i + 1<<". " << menu[i]<<": " << prices[i] << endl;
    }
}

STATES Automata::getState() {
    return state;
}

// Выбор напитка пользователем
void Automata::choice(int index) {
    if (state == STATES::ACCEPT && index >= 0 && index < menu.size()) {
        choiceIndex = index;
        state = STATES::CHECK;
        if (check(choiceIndex)) {
            state = STATES::COOK;
            cout << "Selected drink: " << menu[index] << endl;
            cook(choiceIndex);
        } else if (!check(choiceIndex)) {
            cout << "There are not enough funds in the account. Please deposit the money." << endl;
        }
    }
}

// Проверка наличия необходимой суммы для покупки напитка
bool Automata::check(int index)
{
    if (state == STATES::CHECK) {
        //return cash >= prices[index];
        if (cash >= prices[index]) {
            return true;
        } 
            state == STATES::ACCEPT;
            return false;
        
    }
    return false;
}

// Отмена сеанса обслуживания
void Automata::cancel() {
    if ((state == STATES::ACCEPT) || (state == STATES::CHECK)) {
        cout << "Refund in the amount of "<< cash << endl;
        cash = 0;
        state = STATES::WAIT;
    }
}

// Имитация процесса приготовления напитка
void Automata::cook(int index) {
    if (state == STATES::COOK) { 
        cout << "Cooking " << menu[index] << endl;
        cout << menu[index]<<" is ready." << endl; 
        state = STATES::WAIT;
    }
}

// Завершение обслуживания пользователя
void Automata::finish() {
    cout << "Thanks! Come back again!" << endl;
    state = STATES::WAIT;
}
