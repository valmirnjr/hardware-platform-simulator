#ifndef CPU_HPP
#define CPU_HPP

#include <memory>
#include "../IReadableComponent/ireadablecomponent.hpp"
#include "../../Program/program.hpp"
#include "../../Register/register.hpp"

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
    void simulate();
    DataValue read();
    std::shared_ptr<Component> makeFromFileContent(dict&);
    void setProgram(const Program&);
    std::ostream& outstream(std::ostream &out);
  };

  std::ostream & operator<<(std::ostream&, CPU&);
}


#endif