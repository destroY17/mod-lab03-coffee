#include "Automata.h"
#include <iostream>

int main() {
    try {
        std::vector<std::string> menu = { "Latte", "Glace",
            "Cappuccino", "Espresso" };
        std::vector<int> prices = { 100, 80, 90, 75 };
        Automata automata(menu, prices);
        std::cout << "Automata is running...\n";
        automata.on();
        std::cout << "Automata is " << automata.getState() << std::endl;
        std::cout << "Menu:" << std::endl;
        std::cout << automata.getMenu();
        int coins = 100;
        automata.coin(coins);
        std::cout << coins << " coins accepted" << std::endl;
        std::cout << "Automata is " << automata.getState() << std::endl;
        int drinkIndex = 3;
        automata.choice(drinkIndex);
        std::cout << drinkIndex << " item selected and";
        std::cout << " cooking has started" << std::endl;
        std::cout << "Cooking is finish.";
        std::cout << "Automata is " << automata.getState() << std::endl;
        coins = 30;
        automata.coin(coins);
        std::cout << coins << " coins accepted" << std::endl;
        std::cout << "Automata is " << automata.getState() << std::endl;
        automata.cancel();
        std::cout << "Cancel operation.";
        std::cout << "Automata is " << automata.getState() << std::endl;
        std::cout << "Automata turns off..." << std::endl;
        automata.off();
        std::cout << "Automata is " << automata.getState() << std::endl;
    }
    catch (std::exception ex) {
        std::cout << ex.what();
    }
}
