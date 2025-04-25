#ifndef _CLAPTRAP_HPP_
# define _CLAPTRAP_HPP_

# include <iostream>
# include <string>
# include <iomanip>

typedef std::string str;

class ClapTrap {
	public:
		ClapTrap(str name);
		ClapTrap(ClapTrap const &src);
		~ClapTrap();

		ClapTrap &	operator=(ClapTrap const &rSym);

		int		getHitPoints() const;
		int		getEnergyPoints() const;
		int		getAttackDamage() const;
		void	setHitPoints(int hitPoints);
		void	setEnergyPoints(int energyPoints);
		void	setAttackDamage(int attackDamage);

		void	attack(const str &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
	
	private:
		str	name;
		int	hitPoints;
		int	energyPoints;
		int	attackDamage;
};

#endif