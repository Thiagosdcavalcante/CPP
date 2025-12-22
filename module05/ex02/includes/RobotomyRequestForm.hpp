#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
  private:
    std::string _target;
  public:
    RobotomyRequestForm(const std::string &target);
    virtual ~RobotomyRequestForm(void);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

    virtual void executeAction(void) const;
};

#endif
