#include <iostream>
#include <string>

int main() {
    // Variável string inicializada
    std::string str = "HI THIS IS BRAIN";

    // Ponteiro para a string
    std::string* stringPTR = &str;

    // Referência para a string
    std::string& stringREF = str;

    // Imprimindo os endereços de memória
    std::cout << "Memory address of the string variable: " << &str << std::endl;
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

    // Imprimindo os valores
    std::cout << "Value of the string variable: " << str << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

    return 0;
}