/**
 * MAIN file --> main
 * Name --> Antara Ibnath
 * Email ---> antara.ibnath08@myhunter.cuny.edu
 * This main file is to test for GameItem class
 * Date --> 2025-06-10
 *  I wanted to make it clear, I used W3SCHOOLS a online website that teaches
 *  programming languages
 * as a refrence/ medium to study / if i had issues with my logic
 * 
 * Since there wasnt a concrete list of items that we need to include I based my main on my favorite game SIMS 4, 
 * they had a feature where sims can dig for different crystals throughout the different worlds
 * and sims can collect them, and they have different rarities, weights, and values, and sell them if they want.
 * I tested all enum values based on the difernt crystals you can find
 * 
 * I tested both programs on the same main since my computer will override 2 mains
 */


#include "Inventory.hpp" // Include the header file for Inventory class
#include "GameItem.hpp"  // Include the header file for GameItem class
#include <iostream>  // for std::cout
#include <string>  // for std::string
#include <cctype>  // for std::isupper

int main () {
    //TESTING TASK A
    // Create instances of GameItem with different attributes
    // and print their details to the console


    //// Default none item with no attributes
    GameItem item1("Rock", "A humble hunk of earth found almost anywhere.", NONE, 0, 0);
    std::cout << item1 << "\n";
    std::cout << "---------------------------------------------\n";

    // Common item with basic attributes
    GameItem item2("Quartz", "A sparkling, rose-hued crystal often found gleaming in the wilds of Oasis Springs!", COMMON, 73, 25);
    std::cout << item2 << "\n";
    std::cout << "---------------------------------------------\n";

    // Rare item with more valuable attributes
    GameItem item3("Hematite", "A metallic crystal with a mysterious gleam, often buried in the shadows of rare dig sites like those in Forgotten Grotto.", RARE, 1.5, 125);
    std::cout << item3 << "\n";
    std::cout << "---------------------------------------------\n";

    // Epic item with high value and weight
    GameItem item4("Crandestine", "An elusive, otherworldly crystal that rarely surfaces from deep, secret dig sites, glowing with mysterious iridescence.", EPIC, 1.5, 500);
    std::cout << item4 << "\n";
    std::cout << "---------------------------------------------\n";

    // Legendary item with the highest rarity and value
    GameItem item5("Rainborz", "A radiant, ultra-rare crystal that sparkles with every color of the rainbow, often hidden in far-flung dig sites like Sixam.", LEGENDARY, 3.7, 7500);
    std::cout << item5 << "\n";
    std::cout << "---------------------------------------------\n";


    //TESTING TASK B

    Inventory<std::string> bag;

    // Test: Add items
    bag.addItem("Ruby");
    bag.addItem("Rainborz");
    bag.addItem("Quartz");  

    //using for loop to go through items and get the size
    std::cout << "Items in bag: ";
    for (int i = 0; i < bag.getSize(); ++i) {
        std::cout << bag.getItems()[i] << " ";
    }
    std::cout << std::endl;

    //Testing the getter for size and capacity
    std::cout << "Size: " << bag.getSize() << std::endl;
    std::cout << "Capacity: " << bag.getCapacity() << std::endl;

    //Testing the getter for index
    std::cout << "Index of 'Rainborz': " << bag.getIndexOf("Rainborz") << std::endl;
    std::cout << "Index of 'Orange Topaz' (not in bag): " << bag.getIndexOf("Orange Topaz") << std::endl; //test a case where the item isn’t found in the inventory.


    //Testing the removeItem function
    std::cout << "Removing 'Ruby': " << (bag.removeItem("Ruby") ? "Success" : "Fail") << std::endl;
    std::cout << "Removing 'Orange Topaz': " << (bag.removeItem("Orange Topaz") ? "Success" : "Fail") << std::endl;

    std::cout << "Items in bag after removal: ";
    for (int i = 0; i < bag.getSize(); ++i) {
        std::cout << bag.getItems()[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}



