#include <iostream>
#include <map>
#include <string>
#include <spdlog/spdlog.h>
#include "Common/common.hpp"
#include "Components/Platform/platform.hpp"

using HPS::Platform;

int main(int argc, char *argv[]) {
  HPS::parseArgs(argc, argv);
  HPS::initLogger();

  // Important to starting using spdlog after the logger initialization
  spdlog::trace("Harware Platform Simulator has started!");
  
  Platform mainPlatform(
    "/home/valmir/Documentos/Phelma/S9/OOP/Project/hardware-platform-simulator/test/data/",
    "testdata/platform.txt"
  );
  mainPlatform.load();
  mainPlatform.bindComponents();
  for (int i = 0; i < HPS::numSimulationSteps; i++) {
    mainPlatform.simulate();
  }

  spdlog::trace("Finishing simulation.");
  return 0;
}
