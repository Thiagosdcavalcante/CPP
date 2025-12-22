#include "../includes/Bureaucrat.hpp"
#include "../includes/Colors.hpp"
#include "../includes/AForm.hpp"

Bureaucrat::Bureaucrat(void): _name(""), _grade(0) {
    throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(grade) {
    if (grade > MIN)
        throw GradeTooLowException();
    if (grade < MAX)
        throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other)
        _grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat(void) {}

std::string Bureaucrat::getName(void) const { return _name; }

int Bureaucrat::getGrade(void) const { return _grade; }

void Bureaucrat::incrementGrade(void) {
    if (_grade == MAX)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade(void) {
    if (_grade == MIN)
        throw GradeTooLowException();
    _grade++;
}

void Bureaucrat::signForm(AForm &form) const {
    try {
        form.beSigned(*this);
        std::cout << CLR_SUCCESS << _name << " assinou " << form.getName() << CLR_RESET << std::endl;
    } catch (std::exception &e) {
        std::cerr << CLR_ERROR << _name << " não conseguiu assinar " << form.getName() << " porque " << e.what() << CLR_RESET << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) const {
    try {
        form.execute(*this);
        std::cout << CLR_SUCCESS << _name << " executou " << form.getName() << CLR_RESET << std::endl;
    } catch (std::exception &e) {
        std::cerr << CLR_ERROR << _name << " não conseguiu executar " << form.getName() << " porque " << e.what() << CLR_RESET << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat: grau muito alto";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat: grau muito baixo";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &Br) {
    return os << CLR_INFO << Br.getName() << CLR_RESET << ", grau do burocrata " << Br.getGrade() << ".";
}
