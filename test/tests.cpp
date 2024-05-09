// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"
TEST(AutomataTest, ConstructorInitializesCorrectly) {
    Automata vendingMachine;
    EXPECT_EQ(vendingMachine.state, Automata::STATES::OFF);
    EXPECT_EQ(vendingMachine.cash, 0.0);
    EXPECT_EQ(vendingMachine.choiceIndex, -1);
}

TEST(AutomataTest, OnTurnsOnAutomat) {
    Automata vendingMachine;
    vendingMachine.on();
    EXPECT_EQ(vendingMachine.state, Automata::STATES::ON);
}

TEST(AutomataTest, OffTurnsOffAutomat) {
    Automata vendingMachine;
    vendingMachine.on();
    vendingMachine.off();
    EXPECT_EQ(vendingMachine.state, Automata::STATES::OFF);
}

TEST(AutomataTest, CoinAddsToCash) {
    Automata vendingMachine;
    vendingMachine.coin(5.0);
    EXPECT_EQ(vendingMachine.cash, 5.0);
}

TEST(AutomataTest, ChoiceDoesNotChangeStateIfNotOn) {
    Automata vendingMachine;
    vendingMachine.choice(0); // Выбор напитка
    EXPECT_EQ(vendingMachine.state, Automata::STATES::OFF);
}

TEST(AutomataTest, ChoiceChangesStateIfOn) {
    Automata vendingMachine;
    vendingMachine.on();
    vendingMachine.choice(0); // Выбор напитка
    EXPECT_EQ(vendingMachine.state, Automata::STATES::COOKING);
}

TEST(AutomataTest, CheckReturnsTrueIfEnoughCash) {
    Automata vendingMachine;
    vendingMachine.on();
    vendingMachine.choice(0); // Выбор напитка
    vendingMachine.coin(5.0);
    EXPECT_TRUE(vendingMachine.check());
}

TEST(AutomataTest, CheckReturnsFalseIfNotEnoughCash) {
    Automata vendingMachine;
    vendingMachine.on();
    vendingMachine.choice(0); // Выбор напитка
    EXPECT_FALSE(vendingMachine.check());
}

TEST(AutomataTest, CancelTurnsOffAutomat) {
    Automata vendingMachine;
    vendingMachine.on();
    vendingMachine.choice(0); // Выбор напитка
    vendingMachine.cancel();
    EXPECT_EQ(vendingMachine.state, Automata::STATES::OFF);
}

TEST(AutomataTest, CookChangesStateToFinished) {
    Automata vendingMachine;
    vendingMachine.on();
    vendingMachine.choice(0); // Выбор напитка
    vendingMachine.cook();
    EXPECT_EQ(vendingMachine.state, Automata::STATES::FINISHED);
}

TEST(AutomataTest, FinishTurnsOffAutomat) {
    Automata vendingMachine;
    vendingMachine.on();
    vendingMachine.choice(0); // Выбор напитка
    vendingMachine.finish();
    EXPECT_EQ(vendingMachine.state, Automata::STATES::OFF);
}
