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
 * @param code: the instruction code (ADD, SUB, ...).
 */
Instruction::Instruction(const string code) : code(code) {}

/**
 * @param params: the instruction code code and its arguments in a string format.
 */
Instruction::Instruction(vector<string> &params) {
  code = params[0];
  for (auto p = params.begin() + 1; p != params.end(); ++p) {
    operands.push_back(stod(*p));
  }
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
  return operands.size() >= 2;
}

bool Instruction::isValid() {
  return isCodeValid() && areOpsValid();
}

double Instruction::NOP() {
  return 0;
}

double Instruction::ADD() {
  double res = 0;
  for (auto const &op : operands) {
    res += op;
  }
  return res;
}

double Instruction::SUB() {
  double res = 0;
  bool firstOpIsSet = false;
  for (auto const &op : operands) {
    if (!firstOpIsSet) {
      res = op;
      firstOpIsSet = true;
    } else {
      res -= op;
    }
  }
  return res;
}

double Instruction::MUL() {
  double res = 1;
  for (auto const &op : operands) {
    res *= op;
  }
  return res;
}

double Instruction::DIV() {
  double res = 0;
  bool firstOpIsSet = false;
  for (auto const &op : operands) {
    if (!firstOpIsSet) {
      res = op;
      firstOpIsSet = true;
    } else {
      if (op != 0) {
        res /= op;
      } else {
        throw std::overflow_error("Attempt to divide by zero.");
      }
    }
  }
  return res;
}

std::ostream& Instruction::outstream(std::ostream &out) {
  out << this->toString() << std::endl;
  return out;
}

std::string Instruction::toString() {
  std::stringstream ss;
  ss << code << " ";
  for (auto const &op : operands) {
    ss << op << " ";
  }
  return ss.str();
}

std::ostream& HPS::operator<<(std::ostream &os, Instruction &b) {
  return b.outstream(os);
};
