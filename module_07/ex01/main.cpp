#include "iter.hpp"
#include <string>

int main( void ) {
    int arr[] = {11, 25, 37};

    std::string words[] = {"Thiago", "Santana", "Dantas", "Cavalcante"};

    iter(arr, 3, triple<int>);
    iter(arr, 3, show<int>);

    iter(words, 4, show<std::string>);

    return (0);
}