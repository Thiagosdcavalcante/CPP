#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
  private:
    std::string _target;
  public:
    ShrubberyCreationForm(const std::string &target);
    virtual ~ShrubberyCreationForm(void);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

    virtual void executeAction(void) const;
};

#endif
