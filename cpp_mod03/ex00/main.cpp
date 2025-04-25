#include "ClapTrap.hpp"

int	main() {
	ClapTrap	Robin("Robin");
	ClapTrap	Romeo("Romeo");

	Robin.attack("Roméo");
	Romeo.takeDamage(Robin.getAttackDamage());
	Romeo.beRepaired(2);

	return 0;
}