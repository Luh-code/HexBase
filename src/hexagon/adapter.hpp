#ifndef __HEX_ADAPTER_HPP__
#define __HEX_ADAPTER_HPP__

#include <cstdint>
#include "port.hpp"

namespace Hexagon
{
  class BaseAdapter {};

  template<typename T>
  class Adapter : public BaseAdapter
  {
  public:
    T* port;

  public:
    virtual void test(int32_t* response) = 0;
  };
}

#endif /* end of include guard: __HEX_ADAPTER_HPP__ */
