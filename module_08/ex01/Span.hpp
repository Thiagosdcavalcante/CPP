#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>
# include <algorithm>

  class Span {
	private:
	  std::vector<int> _storage;
	  unsigned int _capacity;
	  Span(void);

	public:
	  Span(unsigned int capacity);
	  Span(const Span &other);
	  Span &operator=(const Span &other);
	  ~Span(void);

	  void addNumber(int number);
	  void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

	  int shortestSpan(void) const;
	  int longestSpan(void) const;
};

#endif