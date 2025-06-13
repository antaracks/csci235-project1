/**
 * Header file --> GameTime
 * Name --> Antara Ibnath
 * Email ---> antara.ibnath08@myhunter.cuny.edu
 * This file is the interface for GameItem class
 * Date --> 2025-06-10
 *  I wanted to make it clear, I used W3SCHOOLS a online website that teaches
 *  programming languages
 * as a refrence/ medium to study / debugging
 * 
 * 
 */

#ifndef GAMEITEM_H  // guard, so that the program only includes it
#define GAMEITEM_H  // if its not included somehwere else 

#include <iostream>
#include <string>
#include <cctype>    // included libraries 


enum Rarity { NONE, COMMON, RARE, EPIC, LEGENDARY };  // a list of names for numbers


class GameItem {

 private:  

 //these are all private,so can only be accesable via the class.

    std::string name_;  //holds name of game item
    std::string description_;  //holds description of game item
    Rarity rarity_;  //holds rarity of game item
    double weight_; //holds weight of game item 
    double value_;  //holds value of item

    //Helper function to convert colors
    std::string rarityToString() const;


    public:

    //Constructors for Project
    GameItem();  //Default constructor 

    //3 Parameter Constructor
    GameItem(std::string name, std::string description, Rarity rarity);
    
    //5 Parameter Constructor
    GameItem(std::string name, std::string description, Rarity rarity, double weight, double value);



    //Getters for Project
    std::string getName() const;  //returns name of game item
    std::string getDescription() const;  //returns description of game item
    Rarity getRarity() const;  //returns rarity of game item
    double getWeight() const;  //returns weight of game item
    double getValue() const;  //returns value of game item


    //Setters for Project
    bool setName(const std::string& name);  //sets name of game item
    bool setDescription(const std::string& description);  //sets description of game item
    bool setRarity(Rarity rarity);  //sets rarity of game item
    bool setWeight(const double& weight);  //sets weight of game item
    bool setValue(const double& value);  //sets value of game item


    //Required Friend Function , needed for formatting & Prinitng
    friend std::ostream& operator<<(std::ostream& os, const GameItem& item);

    //Required overloading operator, needed for gameitem comparison for equality
    bool operator==(const GameItem& other) const;

    //Required overloading operator, needed for gameitem comparison for less than
    bool operator<(const GameItem& other) const;


};



#endif
