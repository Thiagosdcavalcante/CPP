#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <string>
# include <cstdlib>
# include <set>
# include <stdexcept>
# include <algorithm>
# include <ctime>
# include <climits>
# include <cctype>

class PmergeMe {
  private:
    std::vector<int> _vector;
    std::deque<int>  _deque;
    double _timeVec;
    double _timeDeq;

    void parseInput(int argc, char **argv);
    void print(std::string str) const;
    void sortAndMeasure(void);
    void printTimes(void) const;
    static void fordJohnsonVector(std::vector<int>& vec);
    static void fordJohnsonDeque(std::deque<int>& deq);

  public:
    PmergeMe(void);
    ~PmergeMe(void);
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    void process(int argc, char **argv);
};

#endif