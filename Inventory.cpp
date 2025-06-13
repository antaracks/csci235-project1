/**
 * Header file --> Inventory.cpp
 * Name --> Antara Ibnath
 * Email ---> antara.ibnath08@myhunter.cuny.edu
 * This file is the implementation for Inventory class
 * Date --> 2025-06-10
 *  I wanted to make it clear, I used W3SCHOOLS a online website that teaches
 *  programming languages
 * as a refrence/ medium to study / debugging
 * 
 * 
 */




#include "Inventory.hpp"


//This is a template function. The type T can be anything 
template <typename T>
//the definition of the default constructor.
Inventory<T>::Inventory() {
    // inventory can currently hold up to 2 items
    capacity_ = 2;
    // 0 items actually stored in the array
    size_ = 0;
    //Allocate space for 2 items of type T on the heap.
    items_ = new T[capacity_];
}

//Destructor, deallocates the memory used by the items_ array

template <typename T>
Inventory<T>::~Inventory() {
    //deletes the items_ array  
    delete[] items_;
    items_ = nullptr;  
}


// Copy constructor, creates a new Inventory object as a copy of another
template <typename T>
Inventory<T>::Inventory(const Inventory<T>& other) {
    capacity_ = other.capacity_;        // copy capacity
    size_ = other.size_;                // copy size
    items_ = new T[capacity_];          // allocate new array

    for (int i = 0; i < size_; ++i) {   // deep copy the items
        items_[i] = other.items_[i];
    }
}

// Copy assignment operator, assigns the contents of another Inventory to this one
template <typename T>
Inventory<T>& Inventory<T>::operator=(const Inventory<T>& other) {
    if (this != &other) { // Avoid self-assignment
        delete[] items_;  // Clean up existing data

        capacity_ = other.capacity_;
        size_ = other.size_;
        items_ = new T[capacity_]; // New deep array

        for (int i = 0; i < size_; ++i) {
            items_[i] = other.items_[i];
        }
    }
    return *this;
}

//Move Contructor

template <typename T>
Inventory<T>::Inventory(Inventory<T>&& other) noexcept {
    items_ = other.items_;          // copy the array
    size_ = other.size_;
    capacity_ = other.capacity_;

    other.items_ = nullptr;         // Leave the other object empty
    other.size_ = 0;
    other.capacity_ = 0;
}

//Move Assignment Operator

template <typename T>
Inventory<T>& Inventory<T>::operator=(Inventory<T>&& other) noexcept {
    if (this != &other) {
        delete[] items_;             // Clean up current data

        items_ = other.items_;       // Steal data from other
        size_ = other.size_;
        capacity_ = other.capacity_;

        other.items_ = nullptr;      // Reset other
        other.size_ = 0;
        other.capacity_ = 0;
    }
    return *this;
}

//Function that adds items to the array
template <typename T>
void Inventory<T>::addItem(const T& item) {
    if (size_ == capacity_) {
        //Doubling the capacity
        int newCapacity = capacity_ * 2;
        T* newItems = new T[newCapacity];

        //Copy old items into the new array
        for (int i = 0; i < size_; ++i) {
            newItems[i] = items_[i];
        }

        //Clean up old array
        delete[] items_;
        items_ = newItems;
        capacity_ = newCapacity;
    }

    //Add the new item and increase size
    items_[size_] = item;
    size_++;
}

//Function that Remove the first occurrence of the item (if it exists), retain order
template <typename T>
bool Inventory<T>::removeItem(const T& item) {
    for (int i = 0; i < size_; ++i) {
        if (items_[i] == item) {
            // Shift everything left to fill the gap
            for (int j = i; j < size_ - 1; ++j) {
                items_[j] = items_[j + 1];
            }

            size_--; // We now have one less item
            return true;
        }
    }

    return false; // Item not found
}


//Getters

//Getting the size
template <typename T>
int Inventory<T>::getSize() const {
    return size_;
}

//Getting the capacity
template <typename T>
int Inventory<T>::getCapacity() const {
    return capacity_;
}

//Getting the items
template <typename T>
T* Inventory<T>::getItems() const {
    return items_;
}

//Getting the index of an item
template <typename T>
int Inventory<T>::getIndexOf(const T& item) {
    for (int i = 0; i < size_; ++i) {
        if (items_[i] == item) {
            return i;
        }
    }
    return -1; // Not found
}
