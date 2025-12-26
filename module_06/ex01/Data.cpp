#include "Data.hpp"

Data::Data(void){}

Data::~Data(void){}

Data::Data(std::string name, std::string mail):_name(name), _mail(mail){}

Data::Data(const Data &other){
  *this = other;
}

Data &Data::operator=(const Data &other){
  if (this != &other){
	_name = other._name;
	_mail = other._mail;
  }
  return *this;
}


void Data::setName(std::string name){
  _name = name;
}

void Data::setMail(std::string mail){
  _mail = mail;
}

std::string Data::getName(void) const { return _name; }
std::string Data::getMail(void) const { return _mail; }


std::ostream &operator<<(std::ostream &os, const Data &it){
  os<< "Name: " << it.getName() << std::endl << "Mail: " << it.getMail() << std::endl;
  return os;
}