#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA {
private:
    std::string name;
    Weapon& weapon; // Referência para o Weapon (HumanA sempre tem uma arma)

public:
    HumanA(const std::string& name, Weapon& weapon);
    void attack() const;
};

#endif