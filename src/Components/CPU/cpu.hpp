#ifndef CPU_HPP
#define CPU_HPP

#include <memory>
#include <string>
#include "../IReadableComponent/ireadablecomponent.hpp"
#include "../../Program/program.hpp"
#include "../../Register/register.hpp"

// Used by cpu.cpp
#include <sstream>
#include <iostream>
#include <exception>

namespace HPS {
  class CPU : public IReadableComponent {
    Program prog;
    Register reg;
    double frequency;
    int numCores;
    int activeCore;
   
  public:
    CPU();
    CPU(const std::string&, const int&, const double&);
    std::string getType();
    void simulate();
    DataValue read();
    std::shared_ptr<Component> makeFromFileContent(dict&);
    void setProgram(const Program&);
    std::string toString();
  };

  std::ostream & operator<<(std::ostream&, CPU&);
}


#endif