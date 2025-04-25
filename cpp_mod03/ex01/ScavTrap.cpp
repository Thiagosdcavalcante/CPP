#include "ScavTrap.hpp"

ScavTrap::ScavTrap(str name) : ClapTrap() {
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << "An evil ScavTrap appear, be careful with " << this->name << " and his " << this->attackDamage << " attack damage !" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src.getName()) {
	*this = src;
}

ScavTrap::~ScavTrap() {
	std::cout << "Evil ScavTrap " << this->name << " exploded." << std::endl;
}

ScavTrap &	ScavTrap::operator=(ScavTrap const &rSym) {
	if (this != &rSym) {
		this->name = rSym.getName();
		this->hitPoints = rSym.getHitPoints();
		this->energyPoints = rSym.getEnergyPoints();
		this->attackDamage = rSym.getAttackDamage();
	}
	return *this;
}

void	ScavTrap::attack(const str &target) {
	std::cout << "Evil ScavTrap " << this->name << " go for broke " << target << " causing him " << this->attackDamage << " attack damage" << std::endl;
}

void	ScavTrap::guardGate() const {
	std::cout << "Evil ScavTrap " << this->name << " enter in protected mode !" << std::endl;
}