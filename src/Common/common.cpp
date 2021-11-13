#include "common.hpp"

using std::vector;
using std::string;

// Global variable for verbosity control
namespace HPS {
  int verboseLevel = 0;
  int numSimulationSteps = 1;
};

string HPS::DataValue::toString() {
  return (
    "{\n\tvalid = " + std::to_string(this->valid) + "\n\tvalue = " 
    + std::to_string(this->value) + "\n}"
  );
}

void HPS::print(const std::vector<std::string> &v) {
  std::cout << "{ ";
  for (int i = 0; i < v.size(); i++) {
    std::cout << v[i];
    if (i != v.size() - 1) {
      std::cout << ", ";
    }
  }
  std::cout << " }" << std::endl;
}

void HPS::print(const dict &d) {
  std::cout << "{ " << std::endl;
  int i = 0;
  for (auto const &p : d) {
    std::cout << "\t" << p.first << ": " << p.second;
    if (i != d.size() - 1) {
      std::cout << ", ";
    }
    std::cout << std::endl;
    i++;
  }
  std::cout << "}" << std::endl;
}

int HPS::cstrToInt(const char *s) {
  char *p;
  int i = strtol(s, &p, 10);
  if (*p) {
    throw std::bad_cast();
  }
  return i;
}

vector<string> HPS::getDictMissingKeys(const dict &d, const std::vector<std::string> &keys) {
  vector<string> missingKeys;
  for (auto const &k : keys) {
     if (d.count(k) == 0) {
       missingKeys.push_back(k);
     }
  }

  return missingKeys;
}

/**
 * @brief Sets the information that is logged based on the verbose level.
 */
void HPS::initLogger() {
  switch (HPS::verboseLevel) {
  case 1:
    spdlog::set_level(spdlog::level::warn);
    break;
  case 2:
    spdlog::set_level(spdlog::level::info);
    break;
  case 3:
    spdlog::set_level(spdlog::level::debug);
    break;
  case 4:
    spdlog::set_level(spdlog::level::trace);
    break;
  default:
    spdlog::set_level(spdlog::level::warn);
    break;
  }
}

void HPS::parseArgs(int argc, char* argv[]) {
  // Find level of verbosity
  for (int arg = 1; arg < argc; arg++) {
    if ('-' == argv[arg][0]) {
      char *opt = &argv[arg][1];
      while ('v' == *opt) {
        verboseLevel++;
        opt++;
      }
    }
  }

  // Get number of steps. The syntax in the command line is hps.exe -v --steps N,
  // where N is an integer representing the number of desired steps.
  const char *steps = "--steps";
  bool stepsWasSet = false;
  for (int arg = 1; arg < argc; arg++) {
    if (strcmp(steps, argv[arg]) == 0) {
      if (arg + 1 < argc) { // The next argument should be the number of steps
        HPS::numSimulationSteps = cstrToInt(argv[arg + 1]);
        stepsWasSet = true;
      }
    }
  }

  if (!stepsWasSet) {
    spdlog::warn("Using 1 simulation step since no value was specified.");
  }
}
