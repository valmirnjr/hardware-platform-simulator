#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include <string>
#include <vector>

namespace HPS {
  class Instruction {
    std::string code;
    std::pair<double, double> operands;
  
  public:
    Instruction();
    Instruction(const std::string, double op1=0.0, double op2=0.0);
    Instruction(std::vector<std::string>&);
    double execute();
    bool isValid();
    bool isCodeValid();
    bool areOpsValid();
    std::ostream& outstream(std::ostream &out);
  };

  std::ostream & operator<<(std::ostream&, Instruction&);
}

#endif