#include <gtest/gtest.h>
#include "MobisSteering.h"

TEST(MobisSteeringTest, GetSteeringNameTest)
{
	MobisSteering mobisSteering{};
	EXPECT_EQ("MOBIS", mobisSteering.GetSteeringName());
}