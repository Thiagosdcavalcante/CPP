#include "../includes/Bureaucrat.hpp"
#include "../includes/Colors.hpp"
#include "../includes/Form.hpp"

Bureaucrat::Bureaucrat(void): _name(""), _grade(0) {

    std::cout << CLR_INFO << "Bureaucrat default constructor called" << CLR_RESET << std::endl;

    throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat(void){

    std::cout << CLR_DIM << "Bureaucrat destructor called" << CLR_RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name,  int grade)
    : _name(name), _grade(grade) {

    std::cout << CLR_INFO << "Bureaucrat name constructor called" << CLR_RESET << std::endl;

    if (grade > MIN)
        throw GradeTooLowException();
    if (grade < MAX)
        throw GradeTooHighException();
}

Bureaucrat::Bureaucrat( const Bureaucrat &other)
    : _name(other._name), _grade(other._grade) {

    std::cout << CLR_INFO << "Bureaucrat copy constructor called" << CLR_RESET << std::endl;
    *this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
    std::cout << CLR_DIM << "Bureaucrat copy assignment operator called" << CLR_RESET << std::endl;
    if (this != &other){
        _grade = other._grade;
    }
    return *this;
}

std::string    Bureaucrat::getName(void) const{

    return _name;
}

int Bureaucrat::getGrade(void) const{

    return _grade;
}

void  Bureaucrat::incrementGrade(void){

    if(_grade == MAX)
        throw GradeTooHighException();

    _grade--;
}
void  Bureaucrat::decrementGrade(void){

    if (_grade == MIN)
        throw GradeTooLowException();

    _grade++;
}

void Bureaucrat::signForm(Form &Fr){

    try {
        Fr.beSigned(*this);
        std::cout << CLR_SUCCESS << _name << " assinou " << Fr.getName() << CLR_RESET << std::endl;
    } catch (std::exception &e){
        std::cerr << CLR_ERROR << _name << " não conseguiu assinar " << Fr.getName()
                  << " porque " << e.what() << CLR_RESET << std::endl;
    }
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){

    return "Bureaucrat: Grade is too Low";
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){

    return "Bureaucrat: Grade is too High";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &Br) {
    return os << CLR_INFO << Br.getName() << CLR_RESET
              << ", Bureaucrat grade "
              << Br.getGrade()
              << ".";
}
