#ifndef COMMON_HPP
#define COMMON_HPP

#include <string>
#include <vector>
#include <map>
#include <unordered_set>
#include <iostream>

// Used by common.cpp
#include <exception>
#include <spdlog/spdlog.h>

namespace HPS {
  namespace constants {
    // File property keys
    constexpr char TYPE[] = "TYPE";
    constexpr char LABEL[] = "LABEL";
    constexpr char SOURCE[] = "SOURCE";
    constexpr char WIDTH[] = "WIDTH";
    constexpr char COMPONENTS[] = "COMPONENTS";
    constexpr char CORES[] = "CORES";
    constexpr char FREQUENCY[] = "FREQUENCY";
    constexpr char ACCESS[] = "ACCESS";
    constexpr char SIZE[] = "SIZE";
    constexpr char REFRESH[] = "REFRESH";

    // Component types
    constexpr char BUS[] = "BUS";
    constexpr char CPU[] = "CPU";
    constexpr char DISPLAY[] = "DISPLAY";
    constexpr char MEMORY[] = "MEMORY";
    constexpr char PLATFORM[] = "PLATFORM";

    // Other entities names
    constexpr char PROGRAM[] = "PROGRAM";
    constexpr char INSTRUCTION[] = "INSTRUCTION";

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
  template <typename T>
  using vec2d = std::vector<std::vector<T>>;

  typedef struct DataValue {
    bool valid;
    double value;
  } DataValue;

  void print(const std::vector<std::string>&);
  void print(const dict&);

  int cstrToInt(const char*);

  // Validation functions
  std::vector<std::string> getDictMissingKeys(const dict&, const std::vector<std::string>&);

  // Verbose level global variable
  extern int verboseLevel;
  void initLogger();

  // Number of simulation steps global variable
  extern int numSimulationSteps;

  // Command line arguments parser
  void parseArgs(int, char**);
}


#endif