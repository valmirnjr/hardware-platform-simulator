#ifndef COMMON_HPP
#define COMMON_HPP

#include <string>
#include <vector>
#include <map>
#include <unordered_set>
#include <iostream>

namespace HPS {
  namespace constants {
    // File property keys
    constexpr char TYPE[] = "TYPE";
    constexpr char LABEL[] = "LABEL";
    constexpr char COMPONENTS[] = "COMPONENTS";

    // Component types
    constexpr char BUS[] = "BUS";
    constexpr char CPU[] = "CPU";
    constexpr char MEMORY[] = "MEMORY";
    constexpr char PLATFORM[] = "PLATFORM";
    constexpr char PROGRAM[] = "PROGRAM";

    const std::unordered_set<std::string> DEFAULT_KEYS = {
      TYPE, LABEL, BUS, PLATFORM, COMPONENTS
    };

    // Instructions
    constexpr char NOP[] = "NOP";
    constexpr char ADD[] = "ADD";
    constexpr char SUB[] = "SUB";
    constexpr char MUL[] = "MUL";
    constexpr char DIV[] = "DIV";

    const std::unordered_set<std::string> INSTRUCTION_NAMES = {
      NOP, ADD, SUB, MUL, DIV
    };
    
    enum FileStyle {DICT, LINE};
  }

  typedef std::map<std::string, std::string> dict;

  void print(const std::vector<std::string>&);
  void print(const dict&);
}


#endif