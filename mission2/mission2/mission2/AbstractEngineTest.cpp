#include <gmock/gmock-function-mocker.h>
#include <gtest/gtest.h>
#include "AbstractEngine.h"

class TestEngine : public AbstractEngine
{
public:
	~TestEngine() override = default;

	MOCK_METHOD(std::string, GetEngineName, (), (override));
};

TEST(AbstractEngineTest, EngineComponentNameTest)
{
	TestEngine testEngine{};
	testEngine.GetEngineName(); // to touch mock method

	EXPECT_EQ("엔진", testEngine.GetComponentName());
}
