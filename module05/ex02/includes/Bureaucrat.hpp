#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define BRIGHT_CYAN   "\033[96m"
#define BRIGHT_RED    "\033[91m"
#define RESET   "\033[0m"

#include <iostream>
#include <ctime>
#include <string>

class Bureaucrat
{
    private:

    const std::string _name;
    int         _grade;

    public:

    // Constructors 

    Bureaucrat(void);
    Bureaucrat(std::string name, int grade);
    ~Bureaucrat(void);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);

    // metodo get
    std::string getName(void) const;
    int getGrade(void) const;

    //subir ou descer o grau(up or down)
    void upGrade(void);
    void downGrade(void);

    // Exceções

    class GradeTooHighException: public std::exception
    {
        public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException: public std::exception
    {
        public:
        virtual const char *what()const throw();
    };
};

std::ostream &operator<<(std::ostream &osStream, Bureaucrat const &that);

#endif
