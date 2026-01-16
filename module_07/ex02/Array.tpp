#ifndef ARRAY_TPP
# define ARRAY_TPP

# include <iostream>

template<typename T>
Array<T>::Array() : _data(new T[0]), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(0){}

template<typename T>
Array<T>::Array(const Array& other) : _data(new T[n]()), _size(n) {}

#endif