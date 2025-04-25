#include <iostream>
#include <string>

typedef std::string str;

class AAnimal {
	public:
		AAnimal(str type);
		AAnimal();
		AAnimal(AAnimal const &src);
		virtual ~AAnimal();

		AAnimal &	operator=(AAnimal const &rSym);
		str			getType() const;
		void		setType();

		virtual void	makeSound() const = 0;
		virtual void	think() const = 0;
	protected:
		str	_type;
};