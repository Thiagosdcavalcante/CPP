
#ifndef FORM_HPP
# define FORM_HPP


# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

	private:
		static const int MAX = 1;
		static const int MIN = 150;
		const std::string _name;
		bool _signed;
		const int	_gradeToSign;
		const int	_gradeToExecute;

	public:
		AForm(void);
		AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
		~AForm(void);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);

		std::string	getName(void) const;
		int	getSigned(void) const;
		int	getGradeToSign(void) const;
		int	getToExecute(void) const;

		void beSigned(Bureaucrat &Br);

		class GradeTooHighException: public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException: public std::exception {
			public:
				virtual const char *what() const throw();
		};

};

std::ostream &operator<<(std::ostream& os, const AForm &Fr);

#endif