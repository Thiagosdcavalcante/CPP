#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>
# include <ostream>
# include <cstdlib>
# include <ctime>

template<typename T>
class Array {
    private:
        T* _data;
        unsigned int _size;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();

        unsigned int size() const;

        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& array);

# include "Array.tpp"

#endif