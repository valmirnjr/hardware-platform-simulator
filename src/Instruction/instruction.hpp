#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include <string>
#include <vector>
#include <map>

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

    // Instructions
    double NOP();
    double ADD();
    double SUB();
    double MUL();
    double DIV();
  };

  std::ostream & operator<<(std::ostream&, Instruction&);
  typedef double (Instruction::*inst_method_t)();
}

#endif