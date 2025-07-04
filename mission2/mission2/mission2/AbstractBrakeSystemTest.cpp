#include <gmock/gmock-function-mocker.h>
#include <gtest/gtest.h>
#include "AbstractBrakeSystem.h"

class TestBrakeSystem : public AbstractBrakeSystem
{
public:
	~TestBrakeSystem() override = default;

	MOCK_METHOD(std::string, GetBrakeSystemName, (), (override));
};

TEST(AbstractBrakeSystemTest, CarTypeComponentNameTest)
{
	TestBrakeSystem testBrakeSystem{};
	testBrakeSystem.GetBrakeSystemName(); // to touch mock method

	EXPECT_EQ("제동장치", testBrakeSystem.GetComponentName());
}
