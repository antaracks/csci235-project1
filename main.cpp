#include <iostream>
#include "GameItem.hpp"

int main() {
    // Test 1: Full constructor with all valid values
    GameItem item1("Hammer", "Used for building", COMMON, 5, 10);
    std::cout << item1 << "\n";
    std::cout << "-------------------------------------------\n";

    // Test 2: Full constructor with some valid, some invalid values
    GameItem item2("NONE", "This item has no description.", NONE, 1000, 0);
    std::cout << item2 << "\n";
    std::cout << "-------------------------------------------\n";

    // Test 3: Full constructor with some invalid arguments
    GameItem item3("Stone Axe", "Notice how only the invalid arguments take default values!", COMMON, -3, 100);
    std::cout << item3 << "\n";
    std::cout << "-------------------------------------------\n";

    return 0;
}
