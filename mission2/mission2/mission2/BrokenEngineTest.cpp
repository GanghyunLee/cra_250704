#include <gtest/gtest.h>
#include "BrokenEngine.h"

TEST(BrokenEngineTest, GetEngineNameTest)
{
	BrokenEngine brokenEngine{};
	EXPECT_EQ("고장난 엔진", brokenEngine.GetEngineName());
}