#ifndef BASE_HPP
# define BASE_HPP

class Base {
public:
  virtual ~Base();

};

Base* generate();
void identify(Base *p);
void identify(Base &p);

#endif