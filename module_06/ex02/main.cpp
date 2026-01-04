#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h> // Para a função usleep

int main() {

    std::srand(std::time(0));

    std::cout << "--- Iniciando Teste de Identificação Real ---" << std::endl;

    for (int i = 0; i < 10; i++) {
        std::cout << "Teste: " << i + 1 << " -->  ";

        Base* instance = generate();

        identify(instance);

        identify(*instance);

        delete instance;

        std::cout << "-----------------------" << std::endl;

        usleep(100000); 
    }

    return 0;
}