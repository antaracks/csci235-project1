/**
 * CPP file --> GameTime
 * Name --> Antara Ibnath
 * Email ---> antara.ibnath08@myhunter.cuny.edu
 * This file is the implementation for GameItem class
 * Date --> 2025-06-10
 *  I wanted to make it clear, I used W3SCHOOLS a online website that teaches
 *  programming languages
 * as a refrence/ medium to study / if i had issues with my logic
 * 
 * 
 */

 #include "GameItem.hpp" //headerfile created before
 #include <iostream> // for std::cout, std::endl
 #include <cctype> //for std::isupper(char)
 #include <string> // for std::string

 // Default constructor
 GameItem::GameItem() {
    // Default-initaliztion all members, given deafult values
    name_ = "NONE";
    description_ ="This item has no description.";
    rarity_ = NONE;
    weight_ = 0.0;
    value_ = 0.0;

 }

    //Parameterized constructor with 3 arguments, 
    //that tests if it satisfies the requirements
      GameItem::GameItem(std::string name, std::string description, Rarity rarity) {

        //Tests if name is empty or the first character is uppercase, if not
        //the program goes back to default
        if(!name.empty() && std::isupper(name[0]))
        {
            name_ = name;
        }
        else
        {
            name_ = "NONE"; 
      }

    //Tests if description is at least 10 characters long, if not
    //the program goes back to default
      if (description.length() >= 10)
        description_ = description;
    else
        description_ = "This item has no description.";

    //Tests that the rarity parameter that is given, is within
    //the range of the enum values, if not it sets to default.
    if(rarity >= NONE && rarity <= LEGENDARY)
        rarity_ = rarity;
    else
      rarity_ = NONE;

    //Sets weight and value to default zero.
    weight_ = 0.0;
    value_ = 0.0;



 }

//Same constructor as above, however this one weight and height tested as well
  GameItem::GameItem(std::string name, std::string description, Rarity rarity, double weight, double value) {

    //Tests if name is empty or the first character is uppercase, if not
    //the program goes back to default
    if(!name.empty() && std::isupper(name[0]))
    {
        name_ = name;
    }
    else
    {
        name_ = "NONE"; 
    }

    //Tests if description is at least 10 characters long, if not
    //the program goes back to default
    if (description.length() >= 10)
        description_ = description;
    else
        description_ = "This item has no description.";

    //Tests that the rarity parameter that is given, is within
    //the range of the enum values, if not it sets to default.
    if(rarity >= NONE && rarity <= LEGENDARY)
        rarity_ = rarity;
    else
      rarity_ = NONE;
    
    //Tests weight and height, to make sure it is greater than zero
    // or else, it goes back to default
      if (weight > 0)
        weight_ = weight;
    else
        weight_ = 0.0;

    if (value > 0)
        value_ = value;
    else
        value_ = 0.0;
}

//Setters for project

//Setter for name, checks if the name is not empty 
// and starts with an uppercase letter, is invalid if not
   bool GameItem::setName(const std::string& name){
    if(!name.empty() && std::isupper(name[0])) {
        this->name_ = name;
        return true; // Name is valid
    } else {
        return false; 
    }   // Name is invalid
   }

//Setter for description, checks if the description is 
//at least 10 characters long, invalid if not
   bool GameItem::setDescription(const std::string& description) {
    if (description.length() >= 10) {  //Checks character length
        this->description_ = description;
        return true; // Description is valid
    } else {
        return false; 
    }   // Description is invalid
   }

//Setter for rarity, checks if the rarity is within our enum range
    bool GameItem::setRarity(Rarity rarity) {
     if (rarity >= NONE && rarity <= LEGENDARY) { //Checks enum range
          this->rarity_ = rarity;
          return true; // Rarity is valid
     } else {
          return false;
    }    // Rarity is invalid
     }

//Setter for weight, checks if the weight is greater than zero
    bool GameItem::setWeight(const double& weight) {
        if (weight > 0) { //Checks if weight is greater than zero
            this->weight_ = weight;
            return true; // Weight is valid
        } else {
            return false; 
        }  // Weight is invalid
    }

//Setter for value, checks if the value is greater than zero
    bool GameItem::setValue(const double& value) {
        if (value > 0) { //Checks if value is greater than zero
            this->value_ = value;
            return true; // Value is valid
        } else {
            return false; 
        }  // Value is invalid
    }

//Getters for project

//Getter for name, returns the name of the game item
std::string GameItem::getName() const {
    return name_;
}

//Getter for description, returns the description of the game item
std::string GameItem::getDescription() const {
    return description_;
}

//Getter for rarity, returns the rarity of the game item
Rarity GameItem::getRarity() const {
    return rarity_;
}

//Getter for weight, returns the weight of the game item
double GameItem::getWeight() const {
    return weight_;
}

//Getter for value, returns the value of the game item
double GameItem::getValue() const {
    return value_;
}

//Function given to help convert colors

std::string GameItem::rarityToString() const {
    switch (rarity_) {
        case COMMON:
            return "\033[32mCOMMON\033[0m";
        case RARE:
            return "\033[34mRARE\033[0m";
        case EPIC:
            return "\033[35mEPIC\033[0m";
        case LEGENDARY:
            return "\033[33mLEGENDARY\033[0m";
        case NONE:
        default:
            return "NONE";
    }
}

//Friend Function, used for formatting


std::ostream& operator<<(std::ostream& os, const GameItem& item) {  
    //function signature
    os << item.name_ << "(" << item.rarityToString() << ")\n";    
    //Prints the name of the item, followed by the rarity, in parentheses
    os << item.description_ << "\n"; 
     //Prints the description on the next line.
    os << "Weight: " << item.weight_ << "     |     Value: " << item.value_; 
    //Prints the weight and value in a single line, seperated by a pipe
    return os;
}

//Overloading operator for equality to check if two game items are equal


bool GameItem::operator==(const GameItem& other) const {
//Declaring that we are overloading "==" with object other
    return name_ == other.name_ &&
    //Compares this object's name_ with the other object's name_.
           description_ == other.description_ &&
           //Compares 2 item descriptions
           rarity_ == other.rarity_ &&
           //Compares 2 enum values for rarity
           weight_ == other.weight_ &&
           //Compares 2 item weights
           value_ == other.value_;
           //Compares 2 item values
}

//Overloading operator for less than to compare two game items


bool GameItem::operator<(const GameItem& other) const {
    if (name_ < other.name_) return true;  //true if this GameItem is considered less than the other (based on attribute comparison)
    if (name_ > other.name_) return false;  //return false otherwise

    if (rarity_ < other.rarity_) return true;
    if (rarity_ > other.rarity_) return false;

    if (value_ < other.value_) return true;
    if (value_ > other.value_) return false;

    if (weight_ < other.weight_) return true;
    if (weight_ > other.weight_) return false;

    return description_ < other.description_;
}

