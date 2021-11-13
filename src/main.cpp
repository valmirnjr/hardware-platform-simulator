#include <iostream>
#include <map>
#include <string>
#include <spdlog/spdlog.h>
#include "Common/common.hpp"
#include "Components/Platform/platform.hpp"

using HPS::Platform;

int main(int argc, char *argv[]) {
  HPS::parseArgs(argc, argv);
  // Important to starting using spdlog after the logger initialization
  HPS::initLogger();

  std::cout << "Harware Platform Simulator has started!" << std::endl;
  spdlog::info("Number of simulation steps = " + std::to_string(HPS::numSimulationSteps));
  
  Platform mainPlatform(
    "/home/valmir/Documentos/Phelma/S9/OOP/Project/hardware-platform-simulator/test/data/",
    "testdata/platform.txt"
  );
  mainPlatform.load();
  mainPlatform.bindComponents();
  for (int i = 0; i < HPS::numSimulationSteps; i++) {
    spdlog::info("Simulation step number " + std::to_string(i + 1));
    mainPlatform.simulate();
  }

  std::cout << "Finishing simulation." << std::endl;
  return 0;
}
