#include <gmock/gmock-function-mocker.h>
#include <gtest/gtest.h>
#include "AbstractCarType.h"

class TestCarType : public AbstractCarType
{
public:
	~TestCarType() override = default;

	MOCK_METHOD(std::string, GetCarTypeName, (), (override));
};

TEST(AbstractCarTypeTest, CarTypeComponentNameTest)
{
	TestCarType testCarType{};
	testCarType.GetCarTypeName(); // to touch mock method

	EXPECT_EQ("차량 타입", testCarType.GetComponentName());
}
