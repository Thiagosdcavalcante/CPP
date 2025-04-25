#include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat();
		Cat(Cat const &src);
		~Cat();

		Cat &	operator=(Cat const &rSym);

		void	makeSound() const;
	private:
		str		_type;
};