#include <iostream>
#include <string>
#include <ctime>
#include <unistd.h>

typedef std::string str;

class Brain {
	public:
		Brain();
		Brain(Brain const &src);
		~Brain();

		Brain &	operator=(Brain const &rSym);

		str		getRandomIdea() const;
	private:
		str		ideaGenerator() const;
		
		str		_ideas[100];
};