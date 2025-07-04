#include <gtest/gtest.h>
#include "Suv.h"

TEST(SuvTest, SuvCarTypeNameTest)
{
	Suv suv{};
	EXPECT_EQ("Suv", suv.GetCarTypeName());
}