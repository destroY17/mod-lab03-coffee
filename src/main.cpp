#include "Automata.h"
#include <iostream>

int main() {
	try {
		Automata automata({ "Latte", "Glace", "Cappuccino", "Espresso" }, { 100, 80, 90, 75 });
		std::cout << "Automata is running...\n";
		automata.on();
		std::cout << "Automata state is " + automata.getState() + "\n";
		std::cout << "Menu:\n";
		std::cout << automata.getMenu();
		int coins = 100;
		automata.coin(coins);
		std::cout << coins << " coins accepted" << std::endl;
		std::cout << "Automata state is " << automata.getState() << std::endl;
		int drinkIndex = 3;
		automata.choice(drinkIndex);
		std::cout << drinkIndex << " item selected and cooking has started" << std::endl;
		std::cout << "Cooking is finish. Automata is " << automata.getState() << std::endl;
		coins = 30;
		automata.coin(coins);
		std::cout << coins << " coins accepted" << std::endl;
		std::cout << "Automata state is " << automata.getState() << std::endl;
		automata.cancel();
		std::cout << "Cancel operation. Automata state is " << automata.getState() << std::endl;
		std::cout << "Automata turns off..." << std::endl;
		automata.off();
		std::cout << "Automata state is " << automata.getState() << std::endl;
	}
	catch (std::exception ex) {
		std::cout << ex.what();
	}
}
