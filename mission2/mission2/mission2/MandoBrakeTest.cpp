#include <gtest/gtest.h>
#include "MandoBrake.h"

TEST(MandoBrakeTest, GetBrakeSystemNameTest)
{
	MandoBrake mandoBrake{};
	EXPECT_EQ("MANDO", mandoBrake.GetBrakeSystemName());
}