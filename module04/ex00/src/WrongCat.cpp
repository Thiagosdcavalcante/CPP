#include "../include/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal::WrongAnimal("WRONGCAT") {
	this->_type = WrongAnimal::getType();
	std::cout << "[C] Something strange approaches.." << std::endl;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal::WrongAnimal(src) {
	*this = src;
}

WrongCat &	WrongCat::operator=(WrongCat const &rSym) {
	if (this != &rSym) {
		this->_type = rSym._type;
	}
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "[D] Something strange runs away.." << std::endl;
}