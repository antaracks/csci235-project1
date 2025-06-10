#ifndef GAMEITEM_HPP
#define GAMEITEM_HPP

#include <string>

enum Rarity { NONE, COMMON, RARE, EPIC, LEGENDARY };

class GameItem {
private:
    std::string name_;
    std::string description_;
    Rarity rarity_;
    double weight_;
    double value_;

public:
    GameItem(); // Default constructor

    GameItem(std::string name, std::string description, Rarity rarity);

    GameItem(std::string name, std::string description, Rarity rarity, double weight, double value);

    std::string getName() const;
    std::string getDescription() const;
    Rarity getRarity() const;
    double getWeight() const;
    double getValue() const;

    bool setName(const std::string& name);
    bool setDescription(const std::string& description);
    bool setRarity(Rarity rarity);
    bool setWeight(const double& weight);
    bool setValue(const double& value);

    friend std::ostream& operator<<(std::ostream& os, const GameItem& item);

    bool operator==(const GameItem& other) const;
    bool operator<(const GameItem& other) const;
};


std::string rarityToString(Rarity rarity);

#endif // GAMEITEM_HPP

