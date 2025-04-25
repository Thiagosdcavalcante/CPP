#include "../include/AAnimal.hpp"
#include "../include/Dog.hpp"

AAnimal::AAnimal(str type) : _type(type) {
	std::cout << "[C] AAnimal base constructor called for type : " << this->_type << "." << std::endl;
}

AAnimal::AAnimal() : _type("UNKNOWN") {
	std::cout << "[C] AAnimal default constructor called." << std::endl;
}

AAnimal::AAnimal(AAnimal const &src) {
	*this = src;
}

AAnimal &	AAnimal::operator=(AAnimal const &rSym) {
	if (this != &rSym) {
		this->_type = rSym._type;
	}
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "[D] Default destructor called for type : " << this->_type << "." << std::endl;
}

str	AAnimal::getType() const {
	return this->_type;
}