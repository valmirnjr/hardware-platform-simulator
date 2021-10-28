#ifndef BUS_HPP
#define BUS_HPP

#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include "../component.hpp"
#include "../../Common/common.hpp"

namespace HPS {
  class Bus : public Component {
    static const std::string type;
    int width;
    std::string sourceName;
    std::vector<DataValue> pending;
    std::vector<DataValue> ready;
    int readCount;
    
  public:
    Bus();
    Bus(dict&);
    void simulate();
    std::shared_ptr<Component> makeFromFileContent(dict&);
    bool bind(std::shared_ptr<Component>);
    DataValue read();
    int getReadCount();
    std::ostream& outstream(std::ostream&);
  };

  std::ostream & operator<<(std::ostream&, Bus&);
}

#endif