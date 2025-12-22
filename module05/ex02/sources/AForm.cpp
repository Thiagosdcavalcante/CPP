#include "../includes/AForm.hpp"
#include "../includes/Colors.hpp"
#include "../includes/Bureaucrat.hpp"

AForm::AForm(void)
    : _name(""), _signed(false), _gradeToSign(0), _gradeToExecute(0) {
    throw GradeTooHighException();
}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign > MIN || gradeToExecute > MIN)
        throw GradeTooLowException();
    if (gradeToSign < MAX || gradeToExecute < MAX)
        throw GradeTooHighException();
}

AForm::~AForm(void) {}

AForm::AForm(const AForm &other)
    : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other)
        _signed = other._signed;
    return *this;
}

std::string AForm::getName(void) const { return _name; }
bool AForm::getSigned(void) const { return _signed; }
int AForm::getGradeToSign(void) const { return _gradeToSign; }
int AForm::getGradeToExecute(void) const { return _gradeToExecute; }

void AForm::beSigned(Bureaucrat const &b) {
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
}

void AForm::execute(Bureaucrat const & executor) const {
    if (!_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
    executeAction();
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "AForm: grau muito alto";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "AForm: grau muito baixo";
}

const char *AForm::FormNotSignedException::what() const throw() {
    return "AForm: formulario não assinado";
}

std::ostream &operator<<(std::ostream &os, const AForm &Fr) {
    os << CLR_HEADER << "AForm: " << CLR_RESET << Fr.getName() << "\n\tGrade to sign: " << Fr.getGradeToSign()
       << "\n\tGrade to execute: " << Fr.getGradeToExecute()
       << "\n\tStatus: " << (Fr.getSigned() ? (std::string(CLR_SUCCESS) + "Signed" + CLR_RESET) : (std::string(CLR_WARNING) + "Unsigned" + CLR_RESET));
    return os;
}
