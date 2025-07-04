#include <gtest/gtest.h>
#include "ContinentalBrake.h"

TEST(ContinentalBrakeTest, GetBrakeSystemNameTest)
{
	ContinentalBrake continentalBrakeTest{};
	EXPECT_EQ("CONTINENTAL", continentalBrakeTest.GetBrakeSystemName());
}