#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
  private:
    std::string _target;
  public:
    PresidentialPardonForm(const std::string &target);
    virtual ~PresidentialPardonForm(void);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

    virtual void executeAction(void) const;
};

#endif
