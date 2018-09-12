#include <iostream>

using namespace std;

class Hierarchy
{
public:
  virtual void doSome() = 0;
};

class Child1 : public Hierarchy
{
public:
  void doSome()
  {
    cout<<"Soy hijo 1"<<endl;
  }
};

class Child2 : public Hierarchy
{
public:
  void doSome()
  {
    cout<<"Soy hijo 2"<<endl;
  }
};

class Child3 : public Hierarchy
{
public:
  void doSome()
  {
    cout<<"Soy hijo 3"<<endl;
  }
};
