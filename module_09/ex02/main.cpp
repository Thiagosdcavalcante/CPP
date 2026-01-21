#include "PmergeMe.hpp"

int main (int argc, char *argv[]) {
  if (argc < 2){
    std::cerr << "Error" << std::endl;
    return 1;
  }

  try {
    PmergeMe sorter;
    sorter.process(argc, argv);
  }
  catch (const std::exception&e ) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }
  return 0;
}