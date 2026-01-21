#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>

void testVector() {
    std::cout << "------------------------------" << std::endl;
	std::cout << "\n Testing -> std::vector<int> " << std::endl;
    std::cout << "------------------------------" << std::endl;
	std::vector<int> vec;
	for (int i = 1; i <= 10; ++i)
		vec.push_back(i);

	try {
		std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "- - - - - - - - - - -" << std::endl;
		std::cout << "Found in vector: " << *it << std::endl;
        std::cout << "- - - - - - - - - - -" << std::endl;        
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::vector<int>::iterator it = easyfind(vec, 42);
        std::cout << "- - - - - - - - - - -" << std::endl;
		std::cout << "Found in vector: " << *it << std::endl;
        std::cout << "- - - - - - - - - - -" << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void testDeque() {
    std::cout << "-----------------------------" << std::endl;
	std::cout << "\n Testing -> std::deque<int> " << std::endl;
    std::cout << "-----------------------------" << std::endl;
	std::deque<int> dq;
	for (int i = 10; i <= 20; ++i)
		dq.push_back(i);

	try {
		std::deque<int>::iterator it = easyfind(dq, 15);
        std::cout << "- - - - - - - - - - -" << std::endl;
		std::cout << " Found in deque: " << *it << std::endl;
        std::cout << "- - - - - - - - - - -" << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::deque<int>::iterator it = easyfind(dq, 5);
        std::cout << "- - - - - - - - - - -" << std::endl;
		std::cout << " Found in deque: " << *it << std::endl;
        std::cout << "- - - - - - - - - - -" << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void testList() {
    std::cout << "-----------------------------" << std::endl;
	std::cout << "\n  Testing std::list<int>  " << std::endl;
    std::cout << "-----------------------------" << std::endl;
	std::list<int> lst;
	for (int i = 100; i <= 110; ++i)
		lst.push_back(i);

	try {
		std::list<int>::iterator it = easyfind(lst, 105);
        std::cout << "- - - - - - - - - -" << std::endl;
		std::cout << "Found in list: " << *it << std::endl;
        std::cout << "- - - - - - - - - -" << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::list<int>::iterator it = easyfind(lst, 999);
        std::cout << "- - - - - - - - - -" << std::endl;
		std::cout << "Found in list: " << *it << std::endl;
        std::cout << "- - - - - - - -" << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

int main() {
	testVector();
	testDeque();
	testList();
	return 0;
}