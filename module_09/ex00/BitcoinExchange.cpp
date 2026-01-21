#include "BitcoinExchange.hpp"

enum FloatValidationResult {
  FLOAT_OK,
  FLOAT_BAD_FORMAT,
  FLOAT_NEGATIVE,
  FLOAT_TOO_LARGE
};

Bitcoin::Bitcoin(void){
  loadDataBase("./data.csv");
}

Bitcoin::~Bitcoin(void){}

Bitcoin::Bitcoin(const Bitcoin &other){
  *this = other;
}

Bitcoin &Bitcoin::operator=(const Bitcoin &other){
  if (this != &other){
    this->_dataBase = other._dataBase;
  }
  return *this;
}

void Bitcoin::loadDataBase(const std::string &filename){

  std::ifstream file(filename.c_str());
  std::string line;
  std::getline(file, line);

  while(std::getline(file, line)){
    std::stringstream ss(line);
    std::string date, valueStr;

    std::getline(ss, date, ',');
    std::getline(ss, valueStr);

    std::stringstream converter(valueStr);
    float value;
    converter >> value;

    _dataBase[date] = value;
  }
}


static std::string trim(const std::string &str){
  size_t start = str.find_first_not_of(" \t");
  size_t end = str.find_last_not_of(" \t");
  if (start == std::string::npos || end == std::string::npos)
    return "";
  return str.substr(start, end - start + 1);
}

static bool isValidDateFormat(const std::string &date){
  if (date.size() != 10)
    return false;

  for (int i = 0; i < 10; i++){
    if (i == 4 || i == 7){
      if (date[i] != '-')
        return false;

    } else {
      if (!std::isdigit(date[i]))
        return false;
    }
  }
  return true;
}

static bool isRealDate(const std::string &date){
  int year, month, day;
  if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
    return false;
  if (month < 1 || month > 12 || day < 1 || day > 31)
    return false;

  static const int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (month == 2){
    bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (day > (leap ? 29 : 28))
      return false;
  } else {
    if (day > daysInMonth[month - 1])
      return false;
  }
  return true;
}

static FloatValidationResult checkFloatValue(const std::string &valueStr, float &valueOut) {
  char *endPtr = NULL;
  const char *cstr = valueStr.c_str();

  valueOut = strtof(cstr, &endPtr);
  if (*endPtr != '\0')
    return FLOAT_BAD_FORMAT;
  if (valueOut < 0.0f)
    return FLOAT_NEGATIVE;
  if (valueOut > 1000.f)
    return FLOAT_TOO_LARGE;
  return FLOAT_OK;
}

void Bitcoin::loadInput(const std::string &filename){

  std::ifstream file(filename.c_str());
  std::string line;
  std::getline(file, line);

  while(std::getline(file, line)){
    std::stringstream ss(line);
    std::string date, valueStr;

    if (std::count(line.begin(), line.end(), '|') != 1){
      std::cout << "Error: bad input => " << line << std::endl;
      continue;
    }
    std::getline(ss, date, '|');
    std::getline(ss, valueStr);

    date = trim(date);
    valueStr = trim(valueStr);

    if (!isValidDateFormat(date)){
      std::cout << "Error: bad input => " << date << std::endl;
      continue;
    }

    if (!isRealDate(date)){
      std::cout << "Error: bad input => " << date << std::endl;
      continue;
    }


    std::map<std::string, float>::const_iterator it = _dataBase.lower_bound(date);
    if (it != _dataBase.end() && it->first != date){
      if (it != _dataBase.begin()){
        --it;
      } else {
        std::cout << "Error: no valid earlier date for =>" << date << std::endl;
        continue;
      }
    }
    if (it == _dataBase.end()){
      std::cout << "Error: no valid date found for =>" << date << std::endl;
      continue;
    }

    float value;
    FloatValidationResult result = checkFloatValue(valueStr, value);
    if (result != FLOAT_OK) {
      switch (result) {
        case FLOAT_BAD_FORMAT:
          std::cout << "Error: bad input => " << valueStr << std::endl;
          break;
        case FLOAT_NEGATIVE:
          std::cout << "Error: not a positive number." << std::endl;
          break;
        case FLOAT_TOO_LARGE:
          std::cout << "Error: too large a number." << std::endl;
          break;
        default:
          break;
      }
      continue;
    }

    std::cout << date << " => " << value << " = " << value * it->second << std::endl;
  }
}