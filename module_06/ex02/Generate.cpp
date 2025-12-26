#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base* generate(){

  srand(time(0));
  
  int random = rand() % 3;
  switch(random){
	case 0: return new A();
	case 1: return new B();
	default: return new C();
  }
}