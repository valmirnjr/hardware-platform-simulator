#include "common.hpp"
#include <exception>

void HPS::print(const std::vector<std::string> &v) {
  std::cout << "{ ";
  for (int i = 0; i < v.size(); i++) {
    std::cout << v[i];
    if (i != v.size() - 1) {
      std::cout << ", ";
    }
  }
  std::cout << " }" << std::endl;
}

void HPS::print(const dict &d) {
  std::cout << "{ " << std::endl;
  int i = 0;
  for (auto const &p : d) {
    std::cout << "\t" << p.first << ": " << p.second;
    if (i != d.size() - 1) {
      std::cout << ", ";
    }
    std::cout << std::endl;
    i++;
  }
  std::cout << "}" << std::endl;
}

int HPS::cstrToInt(const char *s) {
  char *p;
  int i = strtol(s, &p, 10);
  if (*p) {
    throw std::bad_cast();
  }
  return i;
}
