#include "../include/Brain.hpp"

Brain::Brain() {
	std::cout << "[C] Neuronal creation of brain. Loading..." << std::endl;
	int	i = -1;
	while (++i < 100)
		this->_ideas[i] = this->ideaGenerator();
	std::cout << std::endl;
}

Brain::Brain(Brain const &src) {
	*this = src;
}

Brain &	Brain::operator=(Brain const &rSym) {
	if (this != &rSym) {
		int	i = -1;
		while (++i < 100)
			this->_ideas[i] = rSym._ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "[D] Brain destruction, no turning back. Loading..." << std::endl;
}

str Brain::ideaGenerator() const {
	srand((unsigned)time(NULL) * getpid());
	
	str tmp;
	int min = 4;
	int max = 12;
	int random = min + rand() % (max - min + 1);
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	tmp.reserve(random);
	int i = 0;
	for (int i = 0; i < random; ++i) {
        tmp += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
	return tmp;
}

str	Brain::getRandomIdea() const {
	int	min = 0;
	int	max = 99;
	int random = min + rand() % (max - min + 1);

	return this->_ideas[random];
}