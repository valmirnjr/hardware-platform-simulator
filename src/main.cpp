#include <iostream>
#include <map>
#include <string>
#include "Components/Platform/platform.hpp"

using HPS::Platform;

int main() {
  Platform mainPlatform(
    "/home/valmir/Documentos/Phelma/S9/OOP/Project/hardware-platform-simulator/test/data/",
    "testdata/platform.txt"
  );
  mainPlatform.load();
  mainPlatform.bindComponents();
  mainPlatform.simulate();

  return 0;
}
