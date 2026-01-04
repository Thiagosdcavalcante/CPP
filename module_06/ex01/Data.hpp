#ifndef DATA_HPP
# define DATA_HPP

# include <string>
# include <iostream>


class Data {

	private:
		std::string _name;
		std::string _mail;

	public:
		Data(void);
		~Data(void);
		Data(std::string name, std::string mail);
		Data(const Data &other);
		Data &operator=(const Data &other);

	void setName(std::string name);
	void setMail(std::string mail);

	std::string	getName(void) const;
	std::string	getMail(void) const;
};

std::ostream &operator<<(std::ostream &os, const Data &it);

#endif