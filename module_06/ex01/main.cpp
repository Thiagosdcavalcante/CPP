#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main() {
    Data original("ismael", "ismael@42.com");

    std::cout << "Objeto original:\n" << original << std::endl;

    uintptr_t raw = Serializer::serialize(&original);
    std::cout << "Endereço serializado (uintptr_t): " << raw << std::endl;

    Data* deserialized = Serializer::deserialize(raw);

    std::cout << "Objeto desserializado:\n" << *deserialized << std::endl;

    if (deserialized == &original)
        std::cout << "Sucesso: o ponteiro desserializado é o mesmo do original.\n";
    else
        std::cout << "Erro: ponteiros diferentes.\n";

    return 0;
}