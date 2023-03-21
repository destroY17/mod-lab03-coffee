// Copyright 2022 UNN-IASR
#pragma once
#include <vector>
#include <string>

class Automata {
public:
    Automata(std::vector<std::string> menu, std::vector<int> prices);
    void on();
    void off();
    void coin(int sum);
    std::string getMenu();
    std::string getState();
    void choice(int drinkIndex);
    void cancel();
    
private:
    void check(int drinkIndex);
    void cook(int drinkIndex);
    void finish();
    
private:
    enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK };
    int _cash;
    std::vector<std::string> _menu;
    std::vector<int> _prices;
    STATES _state;
};
