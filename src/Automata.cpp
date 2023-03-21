// Copyright 2022 UNN-IASR
#include "Automata.h"
#include <vector>
#include <string>
#include <iostream>

Automata::Automata(std::vector<std::string> menu, std::vector<int> prices) {
	if (menu.size() != prices.size())
		throw std::invalid_argument("Menu and prices sizes must be equal");
	_cash = 0;
	_menu = menu;
	_prices = prices;
	_state = OFF;
}

void Automata::on() {
	if (_state == OFF)
		_state = WAIT;
}

void Automata::off() {
	if (_state == WAIT || _state == OFF)
		_state = OFF;
	else
		throw std::logic_error("Automata is " + getState());
}

void Automata::coin(int sum) {
	if (sum < 0)
		throw std::invalid_argument("Sum must be > 0");
	if (_state != WAIT && _state != ACCEPT)
		throw std::logic_error("Automata is " + getState());
	_state = ACCEPT;
	_cash += sum;
}

std::string Automata::getMenu() {
	std::string result = "";
	for (int i = 0; i < _menu.size(); i++) {
		result += _menu[i] + " - " + std::to_string(_prices[i]) + "\n";
	}
	return result;
}

std::string Automata::getState() {
	switch (_state) {
	case Automata::OFF:
		return "OFF";
	case Automata::WAIT:
		return "Waiting";
	case Automata::ACCEPT:
		return "Accepting money";
	case Automata::CHECK:
		return "Checking balance";
	case Automata::COOK:
		return "Cooking";
	}
	return "";
}

void Automata::choice(int drinkIndex) {
	if (drinkIndex < 1 || drinkIndex > _menu.size())
		throw std::invalid_argument("Incorrect drinkIndex");
	if (_state != ACCEPT && _state != WAIT)
		throw std::logic_error("Automata is " + getState());
	_state = CHECK;
	check(drinkIndex);
}

void Automata::check(int drinkIndex) {
	if (drinkIndex < 1 || drinkIndex > _menu.size())
		throw std::invalid_argument("Incorrect drinkIndex");
	if (_prices[drinkIndex] > _cash) {
		cancel();
    } else {
		_cash -= _prices[drinkIndex];
		cook(drinkIndex);
	}
}

void Automata::cancel() {
	if (_state == ACCEPT || _state == CHECK) {
		_cash = 0;
		_state = WAIT;
	}
}

void Automata::cook(int drinkIndex) {
	if (_state == CHECK) {
		_state = COOK;
		finish();
	}
}

void Automata::finish() {
	if (_state == COOK)
		_state = WAIT;
}
