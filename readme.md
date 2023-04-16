# HexBase
HexBase is a stripped-down, light-weight, header-only library, providing a framework for applications following the Ports and Adapters design philosophy for agile software development.
The difference between HexBase and other Implementations of Hexagonal software architecture is the replacement of domains with modules.

HexBase is written in C++ and comes with tests.

## INDEV
HexBase is far from done and not all features are implemented yet.

## How to use
### Disclaimer
This documentation was shoe stringed together in about 10 mins, so it isn't very comprehensible. A better Version will be uploaded once all basic features are set.
### Example
To Create a application following the ports and adapters architecture, first create a new class named TestApplication, which inherits from `HexBase::Application`:
```c++
#include <hexbase/application.hpp>

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
```
Next you create a Module and a Port, which we will implement in a second.

As an example Module we are going to create a new class called HelloWorldModule, which inherits from `HexBase::Module`:
```c++
#include <hexbase/module.hpp>
class HelloWorldModule : public HexBase::Module
{
public:
  inline void helloWorld()
  {
    printf("%s\n", "Hello World from a Module!");
  }
};
```
Modules hold all the functionality, which the ports can access. Ports can also be configured to access multiple modules.

Now to the ports. Ports act as a layer of abstraction between Adapters and the Application.
Thus they limit what is accessible to any Adapter and provide genericized functionality for Adapters.

Ports are made specifically for one _type_ of adapter.
So for example you could plug either a Mouse adapter or a Gamepad adapter into a control port (given that both adapters are control adapters), but you cannot plug a microphone adapter into a control port, as it isn't a control adapter.

In this example we will create a HelloWorldPort, which inherits from `HexBase::Port`:
```c++
#include <hexbase/port.hpp>
class HelloWorldPort : public HexBase::Port<HelloWorldModule>
{
public:
  inline HelloWorldPort(HelloWorldModule& module)
  {
    this->module = &module;
  }
};
```

Now for the adapter, create a abstract class HelloWorldAdapter, which inherits from `HexBase::Adapter` to act as an adapter _type_:
```c++
#include <hexbase/adapter.hpp>

class HelloWorldAdapter : public HexBase::Adapter<HelloWorldPort>
{
public:
  virtual void helloWorld() = 0;
};
```

Now create the adapter itself by creating a new class named TestAdapter, which inherits from HelloWorldAdapter:
```c++
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
```
The value of the int32_t* response needs to be 0 by the time TestAdapter::test finishes.
This function is called when mounting an adapter to a port via the application, and expects 0 for a successful check and evaluates everything else as an error.
In our case TestAdapter will act as a API, which we later call in the main function:
```c++
int main()
{
  TestApplication app {};
  TestAdapter testAdapter {};
  app.mountHelloWorldAdapter(&testAdapter);

  testAdapter.helloWorld();
  return 0;
}
```
In the main function, first of all an instance of TestApplication and TestAdapter are being created.
The TestAdapter instance is than being mounted to the app by calling `mountHelloWorldAdapter`.
Than the helloWorld function from the testAdapter is called to verify everything is working.
