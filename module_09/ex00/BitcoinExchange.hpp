#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <iostream>
# include <map>
# include <fstream>
# include <sstream>
# include <algorithm>
# include <cstdlib>

class Bitcoin{

private:
	std::map<std::string, float> _dataBase;

public:
	Bitcoin(void);
	~Bitcoin(void);
	Bitcoin(const Bitcoin &other);
	Bitcoin &operator=(const Bitcoin &other);

	void loadDataBase(const std::string &filename);
	void loadInput(const std::string &filename);
	void printBase(void);

};

#endif