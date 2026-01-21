#ifndef RPN_HPP
# define RPN_HPP


# include <string>
# include <iostream>
# include <stack>
# include <sstream>
# include <stdexcept>
# include <cstdlib>
# include <cctype>

class Polish{
  private:

  public:
    Polish(void);
    ~Polish(void);
    Polish(const Polish &other);
    Polish &operator=(const Polish &other);

    int evaluate(const std::string &expression);

};


#endif