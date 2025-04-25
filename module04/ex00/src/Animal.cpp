#include "../include/Animal.hpp"

Animal::Animal(str type) : _type(type) {
	std::cout << "[C] Animal base constructor called for type : " << this->_type << "." << std::endl;
}

Animal::Animal() : _type("UNKNOWN") {
	std::cout << "[C] Animal default constructor called." << std::endl;
}

Animal::Animal(Animal const &src) {
	*this = src;
}

Animal &	Animal::operator=(Animal const &rSym) {
	if (this != &rSym) {
		this->_type = rSym._type;
	}
	return *this;
}

Animal::~Animal() {
	std::cout << "[D] Default destructor called for type : " << this->_type << "." << std::endl; 
}

str	Animal::getType() const {
	return this->_type;
}

void	Animal::makeSound() const {
	std::cout << "[Unknown Animal] Grrr..." << std::endl;
}