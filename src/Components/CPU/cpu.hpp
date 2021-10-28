#ifndef CPU_HPP
#define CPU_HPP

#include <memory>
#include "../Readable/readable.hpp"
#include "../../Program/program.hpp"
#include "../../Register/register.hpp"

namespace HPS {
  class CPU : public ReadableComponent {
    Program prog;
    Register reg;
    std::string label;
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
    std::string getLabel();
    std::ostream& outstream(std::ostream &out);
  };

  std::ostream & operator<<(std::ostream&, CPU&);
}


#endif