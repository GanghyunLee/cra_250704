#include <gmock/gmock-function-mocker.h>
#include <gtest/gtest.h>
#include "AbstractSteering.h"

class TestSteering : public AbstractSteering
{
public:
	~TestSteering() override = default;

	MOCK_METHOD(std::string, GetSteeringName, (), (override));
};

TEST(AbstractSteeringTest, SteeringComponentNameTest)
{
	TestSteering testSteering{};
	testSteering.GetSteeringName(); // to touch mock method

	EXPECT_EQ("조향장치", testSteering.GetComponentName());
}
