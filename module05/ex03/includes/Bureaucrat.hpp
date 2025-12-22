#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class AForm;

class Bureaucrat {

  private:
    static const int MAX = 1;
    static const int MIN = 150;
    const std::string _name;
    int _grade;

  public:
    Bureaucrat(void);
    Bureaucrat(const std::string name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat(void);

    std::string getName(void) const;
    int getGrade(void) const;

    void incrementGrade(void);
    void decrementGrade(void);

    void signForm(AForm &form) const;
    void executeForm(AForm const & form) const;

    class GradeTooHighException: public std::exception {
      public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException: public std::exception {
      public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &Br);

#endif
