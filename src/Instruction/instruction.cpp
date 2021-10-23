#include "instruction.hpp"
#include <iostream>
#include <functional>
#include "../Common/common.hpp"

using std::vector;
using std::string;
using std::pair;
using std::map;
using std::stod;
using HPS::Instruction;
using HPS::inst_method_t;

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

/**
 * @brief Computes the instruction result.
 * @returns a double containing the result.
 */
double Instruction::execute() {
  // TODO use a single map to all instructions instead of one for each one
  static map<string, inst_method_t> m = {
    { constants::NOP, &Instruction::NOP },
    { constants::ADD, &Instruction::ADD },
    { constants::SUB, &Instruction::SUB },
    { constants::MUL, &Instruction::MUL },
    { constants::DIV, &Instruction::DIV }
  };
  
  // Calls the method corresponding to the given code
  return (*this.*m[code])();
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

double Instruction::NOP() {
  return 0;
}

double Instruction::ADD() {
  return operands.first + operands.second;
}

double Instruction::SUB() {
  return operands.first - operands.second;
}

double Instruction::MUL() {
  return operands.first * operands.second;
}

double Instruction::DIV() {
  return operands.first / operands.second;
}

std::ostream& Instruction::outstream(std::ostream &out) {
  out << code << " " << operands.first << " " << operands.second << std::endl;
  return out;
}

std::ostream& HPS::operator<<(std::ostream &os, Instruction &b) {
  return b.outstream(os);
};
