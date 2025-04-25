#include <iostream>
#include <string>

typedef std::string str;

class WrongAnimal {
	public:
		WrongAnimal(str type);
		WrongAnimal();
		WrongAnimal(WrongAnimal const &src);
		~WrongAnimal();

		WrongAnimal &	operator=(WrongAnimal const &rSym);
		str			getType() const;
		void		setType();

		void	makeSound() const;
	protected:
		str	_type;
};