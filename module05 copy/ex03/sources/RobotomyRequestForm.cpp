#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Colors.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm(target, 72, 45), _target(target) {
    std::srand(std::time(NULL));
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), _target(other._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    (void)other;
    return *this;
}

void RobotomyRequestForm::executeAction(void) const {
    std::cout << CLR_INFO << "Bzzzz... bzzzz..." << CLR_RESET << std::endl;
    int r = std::rand();
    if (r % 2 == 0)
        std::cout << CLR_SUCCESS << _target << " foi robotomizado com sucesso." << CLR_RESET << std::endl;
    else
        std::cout << CLR_ERROR << "A robotomia de " << _target << " falhou." << CLR_RESET << std::endl;
}
