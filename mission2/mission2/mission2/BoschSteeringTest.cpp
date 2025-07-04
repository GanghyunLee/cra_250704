#include <gtest/gtest.h>
#include "BoschSteering.h"

TEST(BoscheSteeringTest, GetSteeringNameTest)
{
	BoschSteering boscheSteering{};
	EXPECT_EQ("BOSCH", boscheSteering.GetSteeringName());
}