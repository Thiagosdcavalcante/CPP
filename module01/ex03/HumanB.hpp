#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB {
private:
    std::string name;
    Weapon* weapon; // Ponteiro para Weapon (HumanB pode não ter uma arma)

public:
    HumanB(const std::string& name);
    void setWeapon(Weapon& weapon);
    void attack() const;
};

#endif