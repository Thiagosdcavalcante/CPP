#include "Base.hpp"
#include <iostream>
#include <ctime>

int main() {


    Base* test= generate();
	Base& testref = *test;
    std::cout << "Identificando via ponteiro: ";
    identify(test);

    std::cout << "Identificando via referência: ";
    identify(*test);

    std::cout << "Identificando via referência: ";
    identify(testref);

    delete test;
    return 0;
}