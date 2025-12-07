#include "../includes/Bureaucrat.hpp"

/* CONSTRUTORES */

Bureaucrat::Bureaucrat(void): _name("random annoying"), _grade(150)
{
    std::cout << _name << " está pronto para ser burocrata!" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
    if (grade < 1) {
        throw GradeTooHighException();
    }
    else if (grade > 150) {
        throw GradeTooLowException();
    }
    std::cout << _name << " está pronto para ser burocrata!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    std::cout << "Construtor de cópia de Bureaucrat chamado." << std::endl;
    *this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Operador de atribuição por cópia chamado." << std::endl;
    if (this != &other)
        _grade = other._grade;
    else
         std::cout << "Autoatribuição detectada! Os objetos já têm o mesmo endereço." <<std::endl;
    return (*this);
}

/* MÉTODO get */

std::string Bureaucrat::getName(void) const
{
    return (_name);
}

int Bureaucrat::getGrade(void) const
{
    return (_grade);
}

/* iNcremento e decremento */

void Bureaucrat::upGrade(void)
{
    if (_grade == 1) {
        throw GradeTooHighException();
    }
    _grade--;
}

void Bureaucrat::downGrade(void)
{
    if (_grade == 150) {
        throw GradeTooLowException();
    }
    _grade++;
}

/* MENSAGENS DE ERRO */

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("O maior grau possível é 1!");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("O menor grau possível é 150!");
}

/* overload bureaucrat */

std::ostream &operator<<(std::ostream &osStream, Bureaucrat const &that)
{
    osStream << that.getName() << ", burocrata grau " << that.getGrade() << ".";
    return(osStream);
}

/* DESTRUTOR */

Bureaucrat::~Bureaucrat(void)
{
    std::cout << _name << " morreu de tédio!" << std::endl;
}
