#include "../includes/Form.hpp"
#include "../includes/Colors.hpp"
#include "../includes/Bureaucrat.hpp"

Form::Form(void)
    : _name(""),
    _gradeToSign(0),
    _gradeToExecute(0)
{

    std::cout << CLR_INFO << "Form default constructor called" << CLR_RESET << std::endl;

    _signed = false;

    throw GradeTooHighException();
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute)
    : _name(name),
    _gradeToSign(gradeToSign),
    _gradeToExecute(gradeToExecute)
{
    std::cout << CLR_INFO << "Form name constructor called" << CLR_RESET << std::endl;

    if (gradeToSign > MIN || gradeToExecute > MIN)
        throw GradeTooLowException();
    if (gradeToSign < MAX || gradeToExecute < MAX)
        throw GradeTooHighException();

    _signed = false;
}

Form::~Form(void){

    std::cout << CLR_DIM << "Form destructor called" << CLR_RESET << std::endl;
}

Form::Form(const Form &other)
    : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    std::cout << CLR_INFO << "Form copy constructor called" << CLR_RESET << std::endl;

    *this = other;
}
Form &Form::operator=(const Form &other){

    std:: cout << CLR_DIM << "Form copy assignment operator called" << CLR_RESET << std::endl;

    if (this != &other){
        _signed = other._signed;
    }
    return *this;
}

std::string    Form::getName(void) const { return _name; }
int    Form::getSigned(void) const { return _signed; }
int    Form::getGradeToSign(void) const { return _gradeToSign; }
int    Form::getToExecute(void) const { return _gradeToExecute; }

void Form::beSigned(Bureaucrat &Br){

    if(Br.getGrade() > _gradeToSign)
        throw Form::GradeTooLowException();
    _signed = true;
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Form: grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Form: grade is too low";
}

std::ostream &operator<<(std::ostream& os, const Form &Fr){

    return os
                << CLR_HEADER << "Form:\t " << CLR_RESET << Fr.getName()
                << "\n\t Grade to sign: " << Fr.getGradeToSign()
                << "\n\t Grade to execute: " << Fr.getToExecute()
                << "\n\t Status: " << (Fr.getSigned() ? (std::string(CLR_SUCCESS) + "Signed" + CLR_RESET) : (std::string(CLR_WARNING) + "Unsigned" + CLR_RESET));
}
