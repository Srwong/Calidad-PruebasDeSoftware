#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

class DataBaseConnect
{
public:
  virtual bool login(string username, string password) {return true;}
  virtual bool logout(string username) { return true; }
  virtual int fetchRecord() { return -1; }
};

class MyDataBase
{
  DataBaseConnect & dbConnect;
public:
  MyDataBase(DataBaseConnect & _dbc) : dbConnect(_dbc) {}

  int Init(string uname, string passwd)
  {
    if(dbConnect.login(uname, passwd) != true)
    {
      cout<<"Failed to connect >>>>"<<endl;
      return  -1;
    }
    else
    {
      cout<<"Successful Connection >>>>"<<endl;
      return 1;
    }
  }
};

class MockDB : public DataBaseConnect
{
public:
  MOCK_METHOD0(fetchRecord, int());
  MOCK_METHOD1(logout, bool(string uname));
  MOCK_METHOD2(login, bool(string uname, string passwd));
};

TEST(MyDBTest, loginTest)
{
  //arrange
  MockDB mdb;
  MyDataBase db(mdb);
  EXPECT_CALL(mdb, login("usuario", "password")).Times(1).WillOnce(Return(true));

  //Act
  int retValue = db.Init("usuario", "password");

  //Assert
  EXPECT_EQ(retValue, 1);
}

TEST(MyDBTest, logoutTest)
{
  MockDB mdb;
  MyDataBase db(mdb);
  EXPECT_CALL(mdb, login("usuario", "password")).Times(1).WillOnce(Return(true));
  int retValue = db.Init("usuario", "password");
  //EXPECT_EQ(retValue, 1);

  EXPECT_CALL(mdb, logout("usuario")).Times(1).WillOnce(Return(true));

  EXPECT_EQ(mdb.logout("usuario"), true);


}

TEST(MyDBTest, fetchTest)
{
  MockDB mdb;
  MyDataBase db(mdb);
  EXPECT_CALL(mdb, login("usuario", "password")).Times(1).WillOnce(Return(true));
  int retValue = db.Init("usuario", "password");
  //EXPECT_EQ(retValue, 1);

  EXPECT_CALL(mdb, fetchRecord()).Times(1).WillOnce(Return(-1));

  EXPECT_EQ(mdb.fetchRecord(), -1);

}
int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
