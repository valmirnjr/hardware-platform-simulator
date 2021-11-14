#ifndef REGISTER_HPP
#define REGISTER_HPP

#include <queue>

// Used by register.cpp
#include <spdlog/spdlog.h>

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