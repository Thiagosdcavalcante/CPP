#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main() {
	ClapTrap	Robin("Robin");
	ClapTrap	*Romeo = new ClapTrap("Roméo");
	ScavTrap	Cyril("Cyril");

	Robin.attack("Cyril");
	Cyril.takeDamage(Robin.getAttackDamage());
	Cyril.beRepaired(18);
	Cyril.guardGate();
	Cyril.attack("Romeo");
	Romeo->takeDamage(Cyril.getAttackDamage());
	delete Romeo;
	return 0;
}