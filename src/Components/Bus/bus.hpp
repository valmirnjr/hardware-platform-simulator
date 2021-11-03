#ifndef BUS_HPP
#define BUS_HPP

#include <string>
#include <vector>
#include <queue>
#include <memory>

#include "../../Common/common.hpp"
#include "../IReadableComponent/ireadablecomponent.hpp"
#include "../IBindableComponent/ibindablecomponent.hpp"

// Used by bus.cpp
#include <iostream>

namespace HPS {
  class Bus : public IReadableComponent, public IBindableComponent {
    static const std::string type;
    int width;
    std::queue<DataValue> pending;
    std::queue<DataValue> ready;
    int readCount;
    
  public:
    Bus();
    Bus(std::string, std::string, int);
    std::string getType();
    void simulate();
    std::shared_ptr<Component> makeFromFileContent(dict&);
    DataValue read();
    int getReadCount();
    std::ostream& outstream(std::ostream&);
  };

  std::ostream & operator<<(std::ostream&, Bus&);
}

#endif