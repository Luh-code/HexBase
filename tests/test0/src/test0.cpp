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

void TestAdapter::test(int* response)
{
  *response = 0;
}

class TestApplication : public HexBase::Application
{
public:
  HelloWorldModule helloWorldModule;

  HelloWorldPort helloWorldPort {helloWorldModule};

public:
  inline void changeHelloWorldAdapter(HelloWorldAdapter* adapter)
  {
    evaluateAdapter(adapter, &helloWorldPort);
  }

  inline void helloWorld()
  {
    printf("%s\n", "Hello World from an adapter!");
  }
};


int main()
{
  TestApplication app;
  TestAdapter testAdapter {};
  app.changeHelloWorldAdapter(&testAdapter);

  testAdapter.helloWorld();
  return 0;
}
