#include "../include/Cat.hpp"

Cat::Cat() : Animal::Animal("CAT") {
	this->_type = Animal::getType();
	std::cout << "[C] A new Cat quietly approaches.." << std::endl;
}

Cat::Cat(Cat const &src) : Animal::Animal(src) {
	*this = src;
}

Cat &	Cat::operator=(Cat const &rSym) {
	if (this != &rSym) {
		this->_type = rSym._type;
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "[D] The Cat runs away.." << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "[Cat] : Meaouw.." << std::endl;
}