#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <exception>
#include <iostream>

void identify(Base *p){
  if (dynamic_cast<A*>(p))
	std::cout << "A" << std::endl;
  else if (dynamic_cast<B*>(p))
	std::cout << "B" << std::endl;
  else if (dynamic_cast<C*>(p))
	std::cout << "C" << std::endl;
  else if (dynamic_cast<Base*>(p))
	std::cout << "Base" << std::endl;
  else
	std::cout << "Unkown Type" << std::endl;
}

void identify(Base &p){
  try {
	(void)dynamic_cast<A&>(p);
	std::cout << "A" << std::endl;
	return ;
  }catch (std::exception &exception){}

  try {
	(void)dynamic_cast<B&>(p);
	std::cout << "B" << std::endl;
	return ;
  }catch (std::exception &exception){}

  try {
	(void)dynamic_cast<C&>(p);
	std::cout << "B" << std::endl;
	return ;
  }catch (std::exception &exception){}

  try {
	(void)dynamic_cast<Base&>(p);
	std::cout << "Base" << std::endl;
	return ;
  }catch (std::exception &exception){}

  std::cout << "Unkown Type" << std::endl;
}