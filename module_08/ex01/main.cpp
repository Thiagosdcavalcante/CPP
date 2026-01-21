#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

void basicTest() {
    std::cout << "- - - - - - - - -" << std::endl;
    std::cout << "Basic test:\n";


    Span numbers(5);

    numbers.addNumber(6);
    numbers.addNumber(3);
    numbers.addNumber(17);
    numbers.addNumber(9);
    numbers.addNumber(11);

    std::cout << "- - - - - - - - -" << std::endl;
    std::cout << "  Shortest span: " << numbers.shortestSpan() << std::endl;
    std::cout << "- - - - - - - - -" << std::endl;
    std::cout << "- - - - - - - - -" << std::endl;
    std::cout << "  Longest span: " << numbers.longestSpan() << std::endl;
    std::cout << "- - - - - - - - -" << std::endl;
}

void bigTest() {
  std::cout << "\nBig test:\n";

  const int size = 10000;
  Span bigSpan(size);

  std::srand(std::time(NULL));
  std::vector<int> manyNumbers;
  for (int i = 0; i < size; ++i)
  manyNumbers.push_back(std::rand());

  bigSpan.addRange(manyNumbers.begin(), manyNumbers.end());

  std::cout << "- - - - - - - - -" << std::endl;
  std::cout << "  Shortest span: " << bigSpan.shortestSpan() << std::endl;
  std::cout << "- - - - - - - - -" << std::endl;
  std::cout << "- - - - - - - - -" << std::endl;
  std::cout << "  Longest span: " << bigSpan.longestSpan() << std::endl;
  std::cout << "- - - - - - - - -" << std::endl;
}

int main() {
  basicTest();
  bigTest();

  return 0;
}