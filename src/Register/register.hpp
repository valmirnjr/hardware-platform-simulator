#ifndef REGISTER_HPP
#define REGISTER_HPP

#include <queue>

namespace HPS {
  class Register {
    std::queue<double> content;
  
  public:
    Register();
    bool isEmpty();
    double read();
    void write(double);
  };
}

#endif