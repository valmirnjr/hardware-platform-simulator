#ifndef CPU_HPP
#define CPU_HPP

#include <memory>
#include "../component.hpp"
#include "../../Program/program.hpp"
#include "../../Register/register.hpp"

namespace HPS {
  class CPU : public Component {
    Program prog;
    Register reg;
    double frequency;
    int numCores;
    int activeCore;
   
  public:
    CPU();
    CPU(const std::string&, const int&, const double&);
    void simulate();
    std::unique_ptr<Component> makeFromFileContent(dict&);
    void setProgram(const Program&);
    std::ostream& outstream(std::ostream &out);
  };

  std::ostream & operator<<(std::ostream&, CPU&);
}


#endif