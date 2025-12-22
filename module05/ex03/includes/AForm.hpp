#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class AForm {
  private:
    static const int MAX = 1;
    static const int MIN = 150;
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute;

  public:
    AForm(void);
    AForm(const std::string name, int gradeToSign, int gradeToExecute);
    virtual ~AForm(void);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);

    std::string getName(void) const;
    bool getSigned(void) const;
    int getGradeToSign(void) const;
    int getGradeToExecute(void) const;

    void beSigned(Bureaucrat const &b);

    void execute(Bureaucrat const & executor) const;
    virtual void executeAction(void) const = 0;

    class GradeTooHighException: public std::exception {
      public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException: public std::exception {
      public:
        virtual const char *what() const throw();
    };

    class FormNotSignedException: public std::exception {
      public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const AForm &Fr);

#endif
