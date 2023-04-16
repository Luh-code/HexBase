#include "hexBase/adapter.hpp"
#include "hexBase/application.hpp"
#include "hexBase/module.hpp"
#include "hexBase/port.hpp"
#include <stdio.h>


class HelloWorldModule : public HexBase::Module
{
public:
  inline void helloWorld()
  {
    printf("%s\n", "Hello World from a Module!");
  }
};


class HelloWorldPort : public HexBase::Port<HelloWorldModule>
{
public:
  inline HelloWorldPort(HelloWorldModule& module)
  {
    this->module = &module;
  }
};


class HelloWorldAdapter : public HexBase::Adapter<HelloWorldPort>
{
public:
  virtual void helloWorld() = 0;
};

class TestAdapter : public HelloWorldAdapter
{
public:
  virtual void test(int* response) override;
  virtual void helloWorld() override;
};

void TestAdapter::helloWorld()
{
  port->module->helloWorld();
}

void TestAdapter::test(int32_t* response)
{
  *response = 0;
}

class TestApplication : public HexBase::Application
{
public:
  HelloWorldModule helloWorldModule;

  HelloWorldPort helloWorldPort {helloWorldModule};

public:
  inline void mountHelloWorldAdapter(HelloWorldAdapter* adapter)
  {
    evaluateAdapter(adapter, &helloWorldPort);
  }
};


int main()
{
  TestApplication app {};
  TestAdapter testAdapter {};
  app.mountHelloWorldAdapter(&testAdapter);

  testAdapter.helloWorld();
  return 0;
}
