#include "../include/Dog.hpp"

Dog::Dog() : Animal::Animal("DOG") {
	this->_type = Animal::getType();
	std::cout << "[C] A new dog appear !" << std::endl;
}

Dog::Dog(Dog const &src) : Animal::Animal(src) {
	*this = src;
}

Dog &	Dog::operator=(Dog const &rSym) {
	if (this != &rSym) {
		this->_type = rSym._type;
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "[D] The dog runs away.." << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "[Dog] : Wouaf wouaf" << std::endl;
}