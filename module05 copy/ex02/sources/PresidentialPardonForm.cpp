#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Colors.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm(target, 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other), _target(other._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    (void)other;
    return *this;
}

void PresidentialPardonForm::executeAction(void) const {
    std::cout << CLR_SUCCESS << _target << " foi perdoado por Zaphod Beeblebrox." << CLR_RESET << std::endl;
}
