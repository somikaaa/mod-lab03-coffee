// Copyright 2022 GHA Test Team
#include "Automata.h"
#include <gtest/gtest.h>

//тест на включение автомата
TEST(AutomataTest, IsOnTest) {
	Automata automata;
	automata.on();
	EXPECT_EQ(automata.getState(), STATES::WAIT);
}

//тест на выключение автомата
TEST(AutomataTest, IsOffTest){
	Automata automata;
	automata.on();
	automata.off();
	EXPECT_EQ(automata.getState(), STATES::OFF);
}

//тест на чтение меню
TEST(AutomataTest, ReadMenuTest) {
	Automata automata;
	automata.on();
	automata.getMenu();
	EXPECT_EQ(automata.getState(), STATES::WAIT);
}

//тест на внесение денег
TEST(AutomataTest, CoinsTest) {
	Automata automata;
	automata.on();
	automata.coin(50);
	EXPECT_EQ(automata.getState(), STATES::ACCEPT);
}

//тест на отмену покупки и возврат денег
TEST(AutomataTest, CancelTest) {
	Automata automata;
	automata.on();
	automata.coin(10);
	automata.cancel();
	EXPECT_EQ(automata.getState(), STATES::WAIT);
}

// тест на имитацию приготовления кофе(1)
TEST(AutomataTest, CookTest1) {
	Automata automata;
	automata.on();
	automata.coin(50);
	automata.choice(0);
	EXPECT_EQ(automata.getState(), STATES::WAIT);
}

// тест на имитацию приготовления чая(2)
TEST(AutomataTest, CookTest2) {
	Automata automata;
	automata.on();
	automata.coin(50);
	automata.choice(1);
	EXPECT_EQ(automata.getState(), STATES::WAIT);
}

// тест на имитацию приготовления горячего шоколада(6)
TEST(AutomataTest, CookTest3) {
	Automata automata;
	automata.on();
	automata.coin(50);
	automata.choice(5);
	EXPECT_EQ(automata.getState(), STATES::WAIT);
}

//тест на имитацию отмены обслуживания и повторного внесения денег
TEST(AutomataTest, CanselAndCoinTest) {
	Automata automata;
	automata.on();
	automata.coin(100);
	automata.cancel();
	automata.coin(50);
	EXPECT_EQ(automata.getState(), STATES::ACCEPT);
}

// тест на имитацию завершения приотовления напитка
TEST(AutomataTest, FinishTest) {
	Automata automata;
	automata.on();
	automata.finish();
	EXPECT_EQ(automata.getState(), STATES::WAIT);
}

