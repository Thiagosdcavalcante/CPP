#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main() {
    Data original("Thiago", "tsantana@42.com");

    std::cout << "Original: " << original << " | Endereço: " << &original << std::endl;

    uintptr_t raw = Serializer::serialize(&original);
    std::cout << "Raw (uintptr_t): " << raw << std::endl;

    Data* result = Serializer::deserialize(raw);
    std::cout << "Deserializado: " << *result << " | Endereço: " << result << std::endl;

    if (result == &original)
        std::cout << "\033[32m✔ SUCESSO: Os ponteiros são idênticos.\033[0m" << std::endl;
    else
        std::cout << "\033[31m✘ ERRO: Os ponteiros divergem!\033[0m" << std::endl;

    return 0;
}