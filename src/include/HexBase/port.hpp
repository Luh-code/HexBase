#ifndef __HEX_PORT_HPP__
#define __HEX_PORT_HPP__

namespace HexBase
{
  class BasePort { };

  template<typename T>
  class Port : public BasePort
  {
  public:
    T* module;

  public:
    inline Port() {};
  };
}

#endif /* end of include guard: __HEX_PORT_HPP__ */
