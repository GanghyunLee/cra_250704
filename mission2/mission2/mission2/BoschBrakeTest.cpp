#include <gtest/gtest.h>
#include "BoschBrake.h"

TEST(BoschBrakeTest, GetBrakeSystemNameTest)
{
	BoschBrake boschBrake{};
	EXPECT_EQ("BOSCH", boschBrake.GetBrakeSystemName());
}