#include "program.hpp"
#include <iostream>

using HPS::Program;
using HPS::Instruction;
using HPS::dict;
using std::string;

Program::Program() {}

Program::Program(vec2d<string> &content) {
  for (auto &params : content) {
    print(params);
    Instruction inst(params);
    if (inst.isValid()) {
      instructions.push_back(inst);
    } else {
      // TODO treat instruction definition error
      std::cout << "Invalid instruction: ";
      print(params);
    }
  }
}

/**
 * @brief Returns the next instruction to be executed and increments the next
 * instruction counter.
 * @returns Instruction to be executed. If all instructions have already been
 * executed, returns a NOP.
 */
Instruction Program::compute() {
  Instruction inst = hasExecutedAll() ? Instruction(constants::NOP) : instructions[nextInstruction];
  nextInstruction++;
  return inst;
}

/**
 * @brief Returns @c true if all program instructions have been executed.
 * @returns bool.
 */
bool Program::hasExecutedAll() {
  return nextInstruction >= instructions.size();
}

std::ostream& Program::outstream(std::ostream &out) {
  out << constants::PROGRAM << ": {" << std::endl;
  for (auto &inst : instructions) {
    out << "\t" << inst;
  }
  out << "}" << std::endl;
  return out;
}

std::ostream & HPS::operator<<(std::ostream &os, Program &b) {
  return b.outstream(os);
};
