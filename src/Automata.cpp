// Copyright 2022 UNN-IASR
#include "Automata.h"


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
        std::cout << "The drinks machine is on." << std::endl;
    }
}

// Выключение автомата
void Automata::off() {
    if (state == STATES::WAIT) {
        state = STATES::OFF;
        std::cout << "The drinks machine is off." << std::endl;
    }
}

// Добавление средств на счет
void Automata::coin(double amount) {
    if (state == STATES::WAIT || state == STATES::ACCEPT) {
        std::cout << "Please deposit the money." << std::endl;
        cash += amount;
        state = STATES::ACCEPT;
        std::cout << "The money was deposited successfully." << std::endl;
        std::cout << "The balance: " << cash << std::endl;
    }
}

void Automata::getMenu() {
    std::cout << "Choose a drink" << std::endl;
    std::cout << "Menu: " << std::endl;
    for (size_t i = 0; i < menu.size(); ++i) {
        std::cout << i + 1 << ". " << menu[i] << ": " << prices[i] << std::endl;
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
            std::cout << "Selected drink: " << menu[index] << std::endl;
            cook(choiceIndex);
        } else if (!check(choiceIndex)) {
            std::cout << "Please deposit the money." << std::endl;
        }
    }
}

// Проверка наличия необходимой суммы для покупки напитка
bool Automata::check(int index) {
    if (state == STATES::CHECK) {
        if (cash >= prices[index]) {
            return true;
        }
            state == STATES::ACCEPT;
            return false;    }
    return false;
}

// Отмена сеанса обслуживания
void Automata::cancel() {
    if ((state == STATES::ACCEPT) || (state == STATES::CHECK)) {
        std::cout << "Refund in the amount of "<< cash << std::endl;
        cash = 0;
        state = STATES::WAIT;
    }
}

// Имитация процесса приготовления напитка
void Automata::cook(int index) {
    if (state == STATES::COOK) {
        std::cout << "Cooking " << menu[index] << std::endl;
        std::cout << menu[index] << " is ready." << std::endl;
        state = STATES::WAIT;
    }
}

// Завершение обслуживания пользователя
void Automata::finish() {
    std::cout << "Thanks! Come back again!" << std::endl;
    state = STATES::WAIT;
}

