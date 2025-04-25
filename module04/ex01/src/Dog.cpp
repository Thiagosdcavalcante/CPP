#include "../include/Dog.hpp"

Dog::Dog() : Animal::Animal("DOG") {
	this->_type = Animal::getType();
	std::cout << "[C] A new dog appear !" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(Dog const &src) : Animal::Animal(src) {
	*this = src;
}

Dog &	Dog::operator=(Dog const &rSym) {
	if (this != &rSym) {
		this->_type = rSym._type;
		this->_brain = rSym._brain;
	}
	return *this;
}

Dog::~Dog() {
	delete this->_brain;
	std::cout << "[D] The dog runs away.." << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "[Dog] : Wouaf wouaf" << std::endl;
}

void	Dog::think() const {
	std::cout << "[Dog] : " + this->_brain->getRandomIdea() << std::endl;
}