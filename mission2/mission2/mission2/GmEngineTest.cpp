#include <gtest/gtest.h>
#include "GmEngine.h"

TEST(GmEngineTest, GetEngineNameTest)
{
	GmEngine gmEngine{};
	EXPECT_EQ("GM", gmEngine.GetEngineName());
}