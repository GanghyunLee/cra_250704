#include <gtest/gtest.h>
#include "Sedan.h"

TEST(SedanTest, SedanCarTypeNameTest)
{
	Sedan sedan{};
	EXPECT_EQ("Sedan", sedan.GetCarTypeName());
}