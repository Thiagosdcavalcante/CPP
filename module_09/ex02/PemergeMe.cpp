#include "PmergeMe.hpp"

struct AItem {
  int     val;
  size_t  pairIdx;
};

struct LessA {
  bool operator()(const AItem& lhs, const AItem& rhs) const {
    return lhs.val < rhs.val;
  }
};

static void build_jacobsthal_order(size_t m, std::vector<size_t>& order) {
  if (m <= 1) return;
  std::vector<size_t> t;
  t.reserve(32);
  t.push_back(0);
  for (size_t k = 1; ; ++k) {
    size_t two_pow_kp1 = (size_t)1 << (k + 1);
    size_t term = (k % 2 == 1) ? (two_pow_kp1 - 1) : (two_pow_kp1 + 1);
    size_t tk = term / 3;
    t.push_back(tk);
    if (tk >= m) break;
    if (k > 60) break;
  }
  for (size_t k = t.size(); k-- > 2; ) {
    size_t from = t[k - 1] + 1;
    size_t to   = t[k];
    if (from > m) continue;
    if (to > m) to = m;
    for (size_t j = to; ; --j) {
      order.push_back(j);
      if (j == from) break;
    }
  }
}

template <typename SizeT>
static void bump_positions_from(std::vector<SizeT>& posA, SizeT insert_index) {
  for (size_t j = 1; j < posA.size(); ++j) {
    if (posA[j] >= insert_index) posA[j] += 1;
  }
}

PmergeMe::PmergeMe(void) : _timeVec(0.0), _timeDeq(0.0) {}
PmergeMe::~PmergeMe(void) {}
PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }
PmergeMe &PmergeMe::operator=(const PmergeMe &other){
  if (this != &other){
    _vector  = other._vector;
    _deque   = other._deque;
    _timeVec = other._timeVec;
    _timeDeq = other._timeDeq;
  }
  return *this;
}

void PmergeMe::print(std::string str) const{
  std::cout << str;
  for (size_t i = 0; i < _vector.size(); ++i) {
    std::cout << _vector[i];
    if (i + 1 != _vector.size()) std::cout << " ";
  }
  std::cout << std::endl;
}

void PmergeMe::fordJohnsonVector(std::vector<int>& vec) {
  const size_t n = vec.size();
  if (n <= 1) return;
  const size_t m = n / 2;
  std::vector<int> a_vals; a_vals.reserve(m);
  std::vector<int> b_vals; b_vals.reserve(m);
  std::vector<AItem> a_items; a_items.reserve(m);
  for (size_t i = 0, p = 1; i + 1 < n; i += 2, ++p) {
    int x = vec[i], y = vec[i + 1];
    int a = (x > y) ? x : y;
    int b = (x > y) ? y : x;
    a_vals.push_back(a);
    b_vals.push_back(b);
    AItem it; it.val = a; it.pairIdx = p;
    a_items.push_back(it);
  }
  bool hasOdd = (n % 2 != 0);
  int oddValue = hasOdd ? vec.back() : 0;
  std::sort(a_items.begin(), a_items.end(), LessA());
  std::vector<int> chain; chain.reserve(n);
  std::vector<size_t> posA(m + 1, 0);
  for (size_t pos = 0; pos < a_items.size(); ++pos) {
    chain.push_back(a_items[pos].val);
    posA[a_items[pos].pairIdx] = pos;
  }
  if (m >= 1) {
    size_t pairIdx_b1 = a_items[0].pairIdx;
    int b1 = b_vals[pairIdx_b1 - 1];
    size_t endPos = posA[pairIdx_b1];
    std::vector<int>::iterator itPos =
      std::lower_bound(chain.begin(), chain.begin() + endPos, b1);
    size_t insIndex = (size_t)(itPos - chain.begin());
    chain.insert(itPos, b1);
    bump_positions_from(posA, insIndex);
  }
  std::vector<size_t> order;
  build_jacobsthal_order(m, order);
  for (size_t k = 0; k < order.size(); ++k) {
    size_t j = order[k];
    if (j == 0 || j > m) continue;
    int bj = b_vals[j - 1];
    size_t endPos = posA[j];
    std::vector<int>::iterator itEnd = chain.begin() + endPos;
    std::vector<int>::iterator itPos = std::lower_bound(chain.begin(), itEnd, bj);
    size_t insIndex = (size_t)(itPos - chain.begin());
    chain.insert(itPos, bj);
    bump_positions_from(posA, insIndex);
  }
  if (hasOdd) {
    std::vector<int>::iterator itPos =
      std::lower_bound(chain.begin(), chain.end(), oddValue);
    chain.insert(itPos, oddValue);
  }
  vec.swap(chain);
}

void PmergeMe::fordJohnsonDeque(std::deque<int>& deq) {
  const size_t n = deq.size();
  if (n <= 1) return;
  const size_t m = n / 2;
  std::vector<int> a_vals; a_vals.reserve(m);
  std::vector<int> b_vals; b_vals.reserve(m);
  std::vector<AItem> a_items; a_items.reserve(m);
  for (size_t i = 0, p = 1; i + 1 < n; i += 2, ++p) {
    int x = deq[i], y = deq[i + 1];
    int a = (x > y) ? x : y;
    int b = (x > y) ? y : x;
    a_vals.push_back(a);
    b_vals.push_back(b);
    AItem it; it.val = a; it.pairIdx = p;
    a_items.push_back(it);
  }
  bool hasOdd = (n % 2 != 0);
  int oddValue = hasOdd ? deq.back() : 0;
  std::sort(a_items.begin(), a_items.end(), LessA());
  std::deque<int> chain;
  std::vector<size_t> posA(m + 1, 0);
  for (size_t pos = 0; pos < a_items.size(); ++pos) {
    chain.push_back(a_items[pos].val);
    posA[a_items[pos].pairIdx] = pos;
  }
  if (m >= 1) {
    size_t pairIdx_b1 = a_items[0].pairIdx;
    int b1 = b_vals[pairIdx_b1 - 1];
    size_t endPos = posA[pairIdx_b1];
    std::deque<int>::iterator itPos =
      std::lower_bound(chain.begin(), chain.begin() + endPos, b1);
    size_t insIndex = (size_t)(itPos - chain.begin());
    chain.insert(itPos, b1);
    bump_positions_from(posA, insIndex);
  }
  std::vector<size_t> order;
  build_jacobsthal_order(m, order);
  for (size_t k = 0; k < order.size(); ++k) {
    size_t j = order[k];
    if (j == 0 || j > m) continue;
    int bj = b_vals[j - 1];
    size_t endPos = posA[j];
    std::deque<int>::iterator itEnd = chain.begin() + endPos;
    std::deque<int>::iterator itPos = std::lower_bound(chain.begin(), itEnd, bj);
    size_t insIndex = (size_t)(itPos - chain.begin());
    chain.insert(itPos, bj);
    bump_positions_from(posA, insIndex);
  }
  if (hasOdd) {
    std::deque<int>::iterator itPos =
      std::lower_bound(chain.begin(), chain.end(), oddValue);
    chain.insert(itPos, oddValue);
  }
  deq.swap(chain);
}

void PmergeMe::sortAndMeasure(void){
  std::clock_t startVec = std::clock();
  fordJohnsonVector(_vector);
  std::clock_t endVec = std::clock();
  std::clock_t startDeq = std::clock();
  fordJohnsonDeque(_deque);
  std::clock_t endDeq = std::clock();
  _timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000.0;
  _timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000.0;
}

void PmergeMe::printTimes(void) const {
  std::cout << "Time to process a range of " << _vector.size()
            << " elements with std::vector : " << _timeVec << " us" << std::endl;
  std::cout << "Time to process a range of " << _deque.size()
            << " elements with std::deque  : " << _timeDeq << " us" << std::endl;
}

void PmergeMe::parseInput(int argc, char **argv){
  std::set<int> seen;
  for (int i = 1; i < argc; ++i) {
    std::string arg = argv[i];
    if (arg.empty())
      throw std::runtime_error("Empty input");
    for (size_t j = 0; j < arg.size(); ++j) {
      if (!std::isdigit(static_cast<unsigned char>(arg[j])))
        throw std::runtime_error("invalid character in input: " + arg);
    }
    long num = std::atol(arg.c_str());
    if (num <= 0 || num > INT_MAX)
      throw std::runtime_error("Number out of range: " + arg);
    if (!seen.insert(static_cast<int>(num)).second)
      throw std::runtime_error("Duplicate number " + arg);
    _vector.push_back(static_cast<int>(num));
    _deque.push_back(static_cast<int>(num));
  }
}

void PmergeMe::process(int argc, char **argv){
  parseInput(argc, argv);
  print("Before: ");
  sortAndMeasure();
  print("After: ");
  printTimes();
}