#ifndef __HEX_PORT_HPP__
#define __HEX_PORT_HPP__

namespace Hexagon
{
  class BasePort { };

  template<typename T>
  class Port : public BasePort
  {
  public:
    T* module;

  public:
    inline Port() {};
    // inline Port(T& module)
    //   : module(module) { }
  };
}

#endif /* end of include guard: __HEX_PORT_HPP__ */
