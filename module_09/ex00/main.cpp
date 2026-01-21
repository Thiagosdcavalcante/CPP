#include <string>
#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv){

	if (argc != 2){
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}

	Bitcoin btc;
  btc.loadInput(argv[1]);

	return (0);
}