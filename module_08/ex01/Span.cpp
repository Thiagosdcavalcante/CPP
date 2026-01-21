#include "Span.hpp"
#include <algorithm>
#include <limits>

Span::Span(unsigned int capacity) : _capacity(capacity) {
}

Span::Span(const Span &other) : _storage(other._storage), _capacity(other._capacity) {
}

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    _storage = other._storage;
    _capacity = other._capacity;
  }
  return *this;
}

Span::~Span(void) {
}

void Span::addNumber(int number) {
  if (_storage.size() >= _capacity) {
    throw std::out_of_range("Span is full");
  }
  _storage.push_back(number);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
  for (std::vector<int>::iterator it = begin; it != end; ++it) {
    addNumber(*it);
  }
}

int Span::shortestSpan(void) const {
  if (_storage.size() < 2) {
    throw std::logic_error("Not enough numbers to compute span");
  }
  
  std::vector<int> sorted(_storage);
  std::sort(sorted.begin(), sorted.end());
  
  int shortest = std::numeric_limits<int>::max();
  for (size_t i = 1; i < sorted.size(); ++i) {
    int span = sorted[i] - sorted[i - 1];
    if (span < shortest) {
      shortest = span;
    }
  }
  
  return shortest;
}

int Span::longestSpan(void) const {
  if (_storage.size() < 2) {
    throw std::logic_error("Not enough numbers to compute span");
  }
  
  int min = *std::min_element(_storage.begin(), _storage.end());
  int max = *std::max_element(_storage.begin(), _storage.end());
  
  return max - min;
}
