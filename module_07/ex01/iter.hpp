#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>
#include <iostream>

template<typename T, typename F>
void iter(T *array, size_t size, F function){
    for (size_t i = 0; i < size; i++)
        function(array[i]);
}

template<typename T>
void triple(T &value){
    value *= 3;
}

template<typename T>
void show(T &value){
    std::cout << "value: " << value << std::endl;
}

#endif