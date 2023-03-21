// Copyright 2022 UNN-IASR

#include <gtest/gtest.h>
#include "Automata.h"

TEST(automataTest, createAutomataIsInvalid) {
    EXPECT_THROW(Automata automata({ "Latte", "Espresso" }, { 100, 80, 90 }),
        std::invalid_argument);
}

TEST(automataTest, onIfAutomataIsOFF) {
    Automata automata({ "Latte", "Glace", "Cappuccino", "Espresso" },
        { 100, 80, 90, 75 });
    automata.on();
    EXPECT_EQ(automata.getState(), "Waiting");
}

TEST(automataTest, onIfAutomataIsON) {
    Automata automata({ "Latte", "Glace", "Cappuccino", "Espresso" },
        { 100, 80, 90, 75 });
    automata.on();
    automata.coin(100);
    automata.on();
    EXPECT_EQ(automata.getState(), "Accepting money");
}

TEST(automataTest, offIsValid) {
    Automata automata({ "Latte", "Glace", "Cappuccino", "Espresso" },
        { 100, 80, 90, 75 });
    automata.on();
    automata.off();
    EXPECT_EQ(automata.getState(), "OFF");
}

TEST(automataTest, offIsInvalid) {
    Automata automata({ "Latte", "Glace", "Cappuccino", "Espresso" },
        { 100, 80, 90, 75 });
    automata.on();
    automata.coin(100);
    EXPECT_THROW(automata.off(), std::logic_error);
}

TEST(automataTest, coinIsValid) {
    Automata automata({ "Latte", "Glace", "Cappuccino", "Espresso" },
        { 100, 80, 90, 75 });
    automata.on();
    automata.coin(100);
    EXPECT_EQ(automata.getState(), "Accepting money");
}

TEST(automataTest, coinIfIncorrectMoney) {
    Automata automata({ "Latte", "Glace", "Cappuccino", "Espresso" },
        { 100, 80, 90, 75 });
    automata.on();
    EXPECT_THROW(automata.coin(-10), std::invalid_argument);
}

TEST(automataTest, coinIfIncorrectState) {
    Automata automata({ "Latte", "Glace", "Cappuccino", "Espresso" },
        { 100, 80, 90, 75 });
    EXPECT_THROW(automata.coin(100), std::logic_error);
}

TEST(automataTest, choiceIsValid) {
    Automata automata({ "Latte", "Glace", "Cappuccino", "Espresso" },
        { 100, 80, 90, 75 });
    automata.on();
    automata.coin(100);
    automata.choice(3);
    EXPECT_EQ(automata.getState(), "Waiting");
}

TEST(automataTest, choiceIfIncorrectIndex) {
    Automata automata({ "Latte", "Glace", "Cappuccino", "Espresso" },
        { 100, 80, 90, 75 });
    automata.on();
    automata.coin(100);
    EXPECT_THROW(automata.choice(-1), std::invalid_argument);
}

TEST(automataTest, choiceIfIncorrectState) {
    Automata automata({ "Latte", "Glace", "Cappuccino", "Espresso" },
        { 100, 80, 90, 75 });
    automata.on();
    EXPECT_THROW(automata.choice(-1), std::invalid_argument);
}

TEST(automataTest, choiceIfIsNotEnoughMoney) {
    Automata automata({ "Latte", "Glace", "Cappuccino", "Espresso" },
        { 100, 80, 90, 75 });
    automata.on();
    automata.coin(10);
    automata.choice(1);
    EXPECT_EQ(automata.getState(), "Waiting");
}

TEST(automataTest, cancelIsValid) {
    Automata automata({ "Latte", "Glace", "Cappuccino", "Espresso" },
        { 100, 80, 90, 75 });
    automata.on();
    automata.coin(50);
    automata.cancel();
    EXPECT_EQ(automata.getState(), "Waiting");
}
