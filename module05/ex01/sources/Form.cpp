
#include "../includes/Form.hpp"

Form::Form(void)
	: _name(""),
	_gradeToSign(0),
	_gradeToExecute(0)
{

	std::cout << "Form default constructor called" << std::endl;

	_signed = false;

	throw GradeTooHighException();
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute)
	: _name(name),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	std::cout << "Form name constructor called" << std::endl;

	if (gradeToSign > MIN || gradeToExecute > MIN)
		throw GradeTooLowException();
	if (gradeToSign < MAX || gradeToExecute < MAX)
		throw GradeTooHighException();

	_signed = false;
}

Form::~Form(void){

	std::cout << "Form destructor called" << std::endl;
}

Form::Form(const Form &other)
	: _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "Form copy constructor called" << std::endl;

	*this = other;
}
Form &Form::operator=(const Form &other){

	std:: cout << "Form copy assignment operator called" << std::endl;

	if (this != &other){
		_signed = other._signed;
	}
	return *this;
}

std::string	Form::getName(void) const { return _name; }
int	Form::getSigned(void) const { return _signed; }
int	Form::getGradeToSign(void) const { return _gradeToSign; }
int	Form::getToExecute(void) const { return _gradeToExecute; }

void Form::beSigned(Bureaucrat &Br){

	if(Br.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Form: grade is to high";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Form: grade is to low";
}

std::ostream &operator<<(std::ostream& os, const Form &Fr){

	return os
				<< "Form:\t " << Fr.getName()
				<< "\n\t Grade to sign: " << Fr.getGradeToSign()
				<< "\n\t Grate to execute: " << Fr.getToExecute()
				<< "\n\t Status: " << (Fr.getSigned() ? "Signed" : "Unsigned");
}