#include "gtest/gtest.h"
#include "sort.h"

using ::testing::ValuesIn;

template <class T>
class TypedFixture : public ::testing::TestWithParam <T>
{
public:
  void SetUp()
  {
    parent = new T;
  }

  void TearDown()
  {
    delete parent;
  }

protected:
  T* parent;
};


typedef ::testing::Types< Bubble, Merge, Quick> implementations;

TYPED_TEST_CASE(TypedFixture, implementations);

TYPED_TEST(TypedFixture, implementations)
{
  int arr[5] = { 10, 4, 22, 30 ,15};
  this -> parent -> sortArray(arr, sizeof(arr)/sizeof(arr[0]));

}
