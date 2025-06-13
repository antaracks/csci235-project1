/**
 * Header file --> Inventory.hpp
 * Name --> Antara Ibnath
 * Email ---> antara.ibnath08@myhunter.cuny.edu
 * This file is the interface for Inventory class
 * Date --> 2025-06-10
 *  I wanted to make it clear, I used W3SCHOOLS a online website that teaches
 *  programming languages
 * as a refrence/ medium to study / debugging
 * 
 * 
 */


//Guards
#ifndef INVENTORY_HPP
#define INVENTORY_HPP

template <typename T> //we add this because this is a class template 

//class name
class Inventory {
    
private:
// This a a pointer to an array of items
    T* items_; 
// The maximum number of items the inventory can hold
    int capacity_; 
// This is the current number of items in the inventory
    int size_; 

public:

//Declaring Default constructor
Inventory();

//Declaring a Destructor
~Inventory();

// Copy constructor
Inventory(const Inventory<T>& other);

//Copying our assigment operator
Inventory<T>& operator=(const Inventory<T>& other);

//Move contructor
Inventory(Inventory<T>&& other) noexcept;

//Move assignment operator
Inventory<T>& operator=(Inventory<T>&& other) noexcept;

//Adds item to the end
void addItem(const T& item);

//Finds and removes first matching item; keeps order
bool removeItem(const T& item);

//Getter that lets us acess array
T* getItems() const;

//Getter that returns how many items are currently stored
int getSize() const;

//Getter that returns maximum capacity of the inventory
int getCapacity() const;

//Getter that searches for an item and gives its position
int getIndexOf(const T& item);


};



#include "Inventory.cpp" //Required at the end of the file 



//So that our Guards work
#endif
