#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;
using ::testing::InSequence;

class Tortuga {
public:
  virtual ~Tortuga() {}
  virtual void PenUp() {}
  virtual void PenDown() {}
  virtual int GetX() {}
  virtual int GetY() {}
  virtual void Forward(int distancia) {}
  virtual void Turn(int grados) {}
  virtual void GoTo(int x, int y) {}
};

class MockTortuga : public Tortuga {
 public:
   MOCK_METHOD0(PenUp, void());
   MOCK_METHOD0(PenDown, void());
   MOCK_METHOD0(GetX, int());
   MOCK_METHOD0(GetY, int());
   MOCK_METHOD1(Forward, void(int distancia));
   MOCK_METHOD1(Turn, void(int grados));
   MOCK_METHOD2(GoTo, void(int x, int y));
};

class Pintor {
	//
  Tortuga & t; //el & va porque se hace referencia a los metodos de la clase tortuga, si no usaria los de Mock por ser virtual
public:
  Pintor(Tortuga & _t) : t(_t){}
  void pinta()
  {
    t.PenDown();
    t.Forward(100);
    t.Turn(90);

    t.Forward(100);
    t.Turn(90);


    t.Forward(100);
    t.Turn(90);


    t.Forward(100);

    t.PenUp();
  }
};

TEST(PruebaDibujo, DibujaAlgo) {
  	// Arrange
    MockTortuga turtle;
    Pintor t(turtle);
    {
      InSequence algo;
      EXPECT_CALL(turtle, PenDown()).Times(1);
      EXPECT_CALL(turtle, Forward(100)).Times(1);

      EXPECT_CALL(turtle, Turn(90)).Times(1);
      EXPECT_CALL(turtle, Forward(100)).Times(1);

      EXPECT_CALL(turtle, Turn(90)).Times(1);
      EXPECT_CALL(turtle, Forward(100)).Times(1);

      EXPECT_CALL(turtle, Turn(90)).Times(1);
      EXPECT_CALL(turtle, Forward(100)).Times(1);

      EXPECT_CALL(turtle, PenUp()).Times(1);

      //EXPECT_CALL(turtle, GetY).WillOnce(Return(0)).WillOnce(Return(100)).WillOnce(Return(100)).WillOnce(Return(0));

    }	// Act
    t.pinta();
	// Assert
	//Como no regresa nada no hay como hacer el assert
}




int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
