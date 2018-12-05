#include "gtest/gtest.h"
#include <iostream>

using namespace std;

//test fixture (compartir datos)
class Foo
{
public:
  void does(){ cout<<"function does\n";}
};

class myFixture : public :: testing::Test
{
public:
  static void SetUpTestCase(){ cout<<"SetUpTestCase\n"; value = new Foo;}
  static void TearDownTestCase(){cout<<"TearDownTestCase\n"; delete value;;}
  virtual void SetUp() {cout<<"setup\n";} //cada test que hice
  virtual void TearDown() {cout<<"TearDown\n"; } //cada test que hice
protected:
  static Foo* value;
};

Foo* myFixture::value = 0;

class myEnvironment : public :: testing::Environment
{
public:
  void SetUp(){cout<<"Environment SetUp\n"; valor_compartido_global = 0;}
  void TearDown(){cout<<"Environment TearDown\n"; delete valor_compartido_global;}
  static Foo *valor_compartido_global;
};

Foo* myEnvironment::valor_compartido_global = 0;

::testing::Environment* const foo_env = ::testing::AddGlobalTestEnvironment(new myEnvironment);

TEST_F(myFixture, prueba1)
{
  value->does();
  ASSERT_TRUE(true);
}

TEST_F(myFixture, prueba2)
{
  value->does();
  ASSERT_TRUE(true);
}

TEST_F(myFixture, prueba3)
{
  value->does();
  ASSERT_TRUE(true);
  static Foo* value;
}
