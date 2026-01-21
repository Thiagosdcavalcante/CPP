#include "RPN.hpp"


Polish::Polish(void){}

Polish::~Polish(void){}

Polish::Polish(const Polish &other){
  (void) other;
}

Polish &Polish::operator=(const Polish &other){
  (void) other;
  return *this;
}

int Polish::evaluate(const std::string &expression){
  std::stack<int> stack;

  for (size_t i =0; i < expression.size(); ++i){
    char c = expression[i];

    if (std::isspace(static_cast<unsigned char>(c)))
      continue;

    if (std::isdigit(static_cast<unsigned char>(c))){
      stack.push(c - '0');
    } else if ( c=='+' || c == '-' || c == '*' || c == '/'){
      if (stack.size()< 2)
        throw std::runtime_error("Insufficient operands");

      int b = stack.top(); stack.pop();
      int a = stack.top(); stack.pop();
      int result;

      switch (c) {
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
        case '/':
                  if (b == 0)
                    throw std::runtime_error("Division by Zero");
                  result = a / b; break;
        default:
                  throw std::runtime_error("Unkown operator");
      }
      stack.push(result);
    } else {
      throw std::runtime_error("Invalid character");
    }
  }
  if (stack.size() != 1){
    throw std::runtime_error("Malformed expression");
  }
  return stack.top();
}