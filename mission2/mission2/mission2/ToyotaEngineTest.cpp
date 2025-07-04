#include <gtest/gtest.h>
#include "ToyotaEngine.h"

TEST(ToyotaEngineTest, GetEngineNameTest)
{
	ToyotaEngine toyotaEngine{};
	EXPECT_EQ("TOYOTA", toyotaEngine.GetEngineName());
}