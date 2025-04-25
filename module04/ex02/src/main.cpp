#include "../include/AAnimal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"
#include "../include/Brain.hpp"

int	main() {
	Cat		Gattino;
	Dog		Rex;

	std::cout << Gattino.getType() << " " << std::endl;
	std::cout << Rex.getType() << " " << std::endl;

	Rex.makeSound();
	Gattino.think();
	Rex.think();

	return 0;
}