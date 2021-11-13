#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include <string>
#include <vector>
#include <map>

// Used by instruction.cpp
#include <sstream>

namespace HPS {
  class Instruction {
    std::string code;
    std::vector<double> operands;
  
  public:
    Instruction();
    Instruction(const std::string);
    Instruction(std::vector<std::string>&);
    double execute();
    bool isValid();
    bool isCodeValid();
    bool areOpsValid();
    std::ostream& outstream(std::ostream &out);
    std::string toString();

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