#include "instruction.hpp"
#include <iostream>
#include "../Common/common.hpp"

using HPS::Instruction;
using std::vector;
using std::string;
using std::pair;
using std::stod;

Instruction::Instruction() {}

/**
 * @param code: the instruction code.
 * @param op1: the instruction first operand, by default 0.0.
 * @param op2: the instruction second operand, by default 0.0.
 */
Instruction::Instruction(const string code, double op1/* =0.0 */, double op2/* =0.0 */) 
  : code(code), operands(pair<double, double>(op1, op2)) {
}

Instruction::Instruction(vector<string> &params) {
  // TODO check if instruction params are valid
  code = params[0];
  operands = pair<double, double>(stod(params[1]), stod(params[2]));
}

double Instruction::execute() {
  // TODO Code execute fnc
  return 0;
}

bool Instruction::isCodeValid() {
  return constants::INSTRUCTION_NAMES.count(code) > 0;
}

bool Instruction::areOpsValid() {
  // TODO verify if operands are valid according to the operation
  return true;
}

bool Instruction::isValid() {
  return isCodeValid() && areOpsValid();
}

std::ostream& Instruction::outstream(std::ostream &out) {
  out << code << " " << operands.first << " " << operands.second << std::endl;
  return out;
}

std::ostream& HPS::operator<<(std::ostream &os, Instruction &b) {
  return b.outstream(os);
};

