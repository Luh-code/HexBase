#ifndef __HEX_APPLICATION_HPP__
#define __HEX_APPLICATION_HPP__

#include "adapter.hpp"
#include <stdio.h>

namespace Hexagon
{
  class Application
  {
  public:
    template<class G>
    inline void evaluateAdapter(Adapter<G>* adapter, G* port)
    {
      if (!adapter)
      {
        printf("%s\n", "Adapter cannot be null!");
        return;
      }
      if (!port)
      {
        printf("%s\n", "Port cannot be null!");
        return;
      }
      adapter->port = port;
      int32_t r = 0;
      adapter->test(&r);
      switch (r)
      {
        case -1:
          printf("%s\n", "No Response from adapter!");
          break;
        case 0:
          printf("%s\n", "Adapter working as intended!");
          return;
        default:
          printf("%s\n", "An unknown error occured in an adapter!");
          break;
      }
      adapter->port = nullptr;
    }
  };
}

#endif /* end of include guard: __HEX_APPLICATION_HPP__ */
