#include <iostream>
#include <iomanip> // for std::setw and std::fixed
#include "GameItem.hpp"

GameItem::GameItem() {
    name_ = "NONE";
    description_ = "This item has no description.";
    rarity_ = NONE;
    weight_ = 0;
    value_ = 0;
}

GameItem::GameItem(std::string name, std::string description, Rarity rarity) {
    // Name validation: must not be empty and must start with uppercase
    if (!name.empty() && std::isupper(name[0])) {
        name_ = name;
    } else {
        name_ = "NONE";
    }

    // Description validation: at least 10 characters
    if (description.length() >= 10) {
        description_ = description;
    } else {
        description_ = "This item has no description.";
    }

    // Rarity validation: must be between 0 and 4 (inclusive)
    if (rarity >= NONE && rarity <= LEGENDARY) {
        rarity_ = rarity;
    } else {
        rarity_ = NONE;
    }

    // Weight and value default to 0
    weight_ = 0;
    value_ = 0;
}

GameItem::GameItem(std::string name, std::string description, Rarity rarity, double weight, double value) {
    // Validate name
    if (!name.empty() && std::isupper(name[0])) {
        name_ = name;
    } else {
        name_ = "NONE";
    }

    // Validate description
    if (description.length() >= 10) {
        description_ = description;
    } else {
        description_ = "This item has no description.";
    }

    // Validate rarity
    if (rarity >= NONE && rarity <= LEGENDARY) {
        rarity_ = rarity;
    } else {
        rarity_ = NONE;
    }

    // Validate weight
    if (weight > 0) {
        weight_ = weight;
    } else {
        weight_ = 0;
    }

    // Validate value
    if (value > 0) {
        value_ = value;
    } else {
        value_ = 0;
    }
}

std::string GameItem::getName() const {
    return name_;
}

std::string GameItem::getDescription() const {
    return description_;
}

Rarity GameItem::getRarity() const {
    return rarity_;
}

double GameItem::getWeight() const {
    return weight_;
}

double GameItem::getValue() const {
    return value_;
}

bool GameItem::setName(const std::string& name) {
    if (!name.empty() && std::isupper(name[0])) {
        name_ = name;
        return true;
    }
    return false;
}

bool GameItem::setDescription(const std::string& description) {
    if (description.length() >= 10) {
        description_ = description;
        return true;
    }
    return false;
}

bool GameItem::setRarity(Rarity rarity) {
    if (rarity >= NONE && rarity <= LEGENDARY) {
        rarity_ = rarity;
        return true;
    }
    return false;
}

bool GameItem::setWeight(const double& weight) {
    if (weight > 0) {
        weight_ = weight;
        return true;
    }
    return false;
}

bool GameItem::setValue(const double& value) {
    if (value > 0) {
        value_ = value;
        return true;
    }
    return false;
}

std::string rarityToString(Rarity rarity) {
    switch (rarity) {
        case NONE:      return "\033[90mN/A\033[0m";        // Gray
        case COMMON:    return "\033[32mCOMMON\033[0m";     // Green
        case RARE:      return "\033[34mRARE\033[0m";       // Blue
        case EPIC:      return "\033[35mEPIC\033[0m";       // Magenta
        case LEGENDARY: return "\033[33mLEGENDARY\033[0m";  // Yellow
        default:        return "\033[90mUNKNOWN\033[0m";
    }
}


std::ostream& operator<<(std::ostream& os, const GameItem& item) {
    os << item.name_ << " (" << rarityToString(item.rarity_) << ")\n";
    os << item.description_ << "\n";
    os << "Weight: " << item.weight_
       << "     |     Value: " << item.value_;
    return os;

}

bool GameItem::operator==(const GameItem& other) const {
    return name_ == other.name_ &&
           description_ == other.description_ &&
           rarity_ == other.rarity_ &&
           weight_ == other.weight_ &&
           value_ == other.value_;
}

bool GameItem::operator<(const GameItem& other) const {
    if (name_ != other.name_) return name_ < other.name_;
    if (rarity_ != other.rarity_) return rarity_ < other.rarity_;
    if (value_ != other.value_) return value_ < other.value_;
    if (weight_ != other.weight_) return weight_ < other.weight_;
    return description_ < other.description_;
}
