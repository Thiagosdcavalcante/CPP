#include "AForm.hpp"

AForm::AForm(void)
    : _name(""),
      _gradeToSign(0),
      _gradeToExecute(0),
      _signed(false)
{
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute)
    : _name(name),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute),
      _signed(false)
{
    std::cout << "AForm name constructor called" << std::endl;
    if (gradeToSign > MIN || gradeToExecute > MIN)
        throw GradeTooLowException();
    if (gradeToSign < MAX || gradeToExecute < MAX)
        throw GradeTooHighException();
}

AForm::~AForm(void)
{
    std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm(const AForm &other)
    : _name(other._name),
      _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute),
      _signed(other._signed)
{
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        _name = other._name;
        _gradeToSign = other._gradeToSign;
        _gradeToExecute = other._gradeToExecute;
        _signed = other._signed;
    }

    std::cout << "AForm copy assignment operator called" << std::endl;
	
    return *this;
}

std::string AForm::getName(void) const { return _name; }
bool AForm::getSigned(void) const { return _signed; }
int AForm::getGradeToSign(void) const { return _gradeToSign; }
int AForm::getGradeToExecute(void) const { return _gradeToExecute; }

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
    return "Form: grade is too high";
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
    return "Form: grade is too low";
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    return os
        << "Form:\t " << form.getName()
        << "\n\t Grade to sign: " << form.getGradeToSign()
        << "\n\t Grade to execute: " << form.getGradeToExecute()
        << "\n\t Status: " << (form.getSigned() ? "Signed" : "Unsigned");
}