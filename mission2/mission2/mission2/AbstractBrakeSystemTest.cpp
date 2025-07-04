#include <gmock/gmock-function-mocker.h>
#include <gtest/gtest.h>
#include "AbstractBrakeSystem.h"

class TestBrake : public AbstractBrakeSystem
{
public:
	~TestBrake() override = default;

	MOCK_METHOD(std::string, GetBrakeSystemName, (), (override));
};

TEST(AbstractBrakeSystemTest, CarTypeComponentNameTest)
{
	TestBrake testBrakeSystem{};
	testBrakeSystem.GetBrakeSystemName(); // to touch mock method

	EXPECT_EQ("제동장치", testBrakeSystem.GetComponentName());
}
