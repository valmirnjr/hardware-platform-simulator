#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include "../Common/common.hpp"
#include "../Instruction/instruction.hpp"
#include <vector>

namespace HPS {
  class Program {
    std::vector<Instruction> instructions;
    int nextInstruction;
  
  public:
    Program();
    Program(vec2d<std::string>&);
    Instruction compute();
    bool hasExecutedAll();
    std::ostream& outstream(std::ostream &out);
  };

  std::ostream & operator<<(std::ostream&, Program&);
}

#endif
