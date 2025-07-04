#include <gtest/gtest.h>
#include "WiaEngine.h"

TEST(WiaEngineTest, GetEngineNameTest)
{
	WiaEngine wiaEngine{};
	EXPECT_EQ("WIA", wiaEngine.GetEngineName());
}