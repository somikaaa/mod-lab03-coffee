// Copyright 2022 UNN-IASR
#pragma once
#include <iostream>
#include <string>
#include <vector>

enum class STATES {
    OFF, WAIT, ACCEPT, CHECK, COOK
};

class Automata {
 private:
    double cash;
    std::vector<std::string> menu;
    std::vector<double> prices;
    STATES state;
    int choiceIndex;

 public:
    Automata();
    void on();
    void off();
    void coin(double amount);
    void getMenu();
    STATES getState();
    void choice(int index);
    bool check(int index);
    void cancel();
    void cook(int index);
    void finish();
};
