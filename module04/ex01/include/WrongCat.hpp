#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		WrongCat(WrongCat const &src);
		~WrongCat();

		WrongCat &	operator=(WrongCat const &rSym);

		void	makeSound() const;
	private:
		str		_type;
};