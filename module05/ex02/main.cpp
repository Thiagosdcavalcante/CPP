#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/Colors.hpp"
#include <iostream>

int main(void)
{
    try {
        Bureaucrat bob("Bob", 1);
        Bureaucrat john("John", 150);

        ShrubberyCreationForm shrub("casa");
        RobotomyRequestForm robo("Bender");
        PresidentialPardonForm pres("Marvin");

    std::cout << CLR_HEADER << "--- Shrubbery ---" << CLR_RESET << std::endl;
    std::cout << shrub << std::endl;
    bob.signForm(shrub);
    bob.executeForm(shrub);

    std::cout << CLR_HEADER << "--- Robotomy ---" << CLR_RESET << std::endl;
    john.signForm(robo);
    bob.signForm(robo);
    bob.executeForm(robo);

    std::cout << CLR_HEADER << "--- Pardon ---" << CLR_RESET << std::endl;
    bob.signForm(pres);
    bob.executeForm(pres);

    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
