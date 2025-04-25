#include <iostream>
#include <string>

typedef std::string str;

class Animal {
	public:
		Animal(str type);
		Animal();
		Animal(Animal const &src);
		virtual ~Animal();

		Animal &	operator=(Animal const &rSym);
		str			getType() const;
		void		setType();

		virtual void	makeSound() const;
	protected:
		str	_type;
};