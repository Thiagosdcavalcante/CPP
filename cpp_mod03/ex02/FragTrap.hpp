#ifndef _FRAGTRAP_HPP_
# define _FRAGTRAP_HPP_

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap(str name);
		FragTrap(FragTrap const &src);
		FragTrap();
		~FragTrap();

		FragTrap &	operator=(FragTrap const &rSym);

		void	highFivesGuys(void);
	private:
};

#endif