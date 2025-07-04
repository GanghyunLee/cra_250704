#include <gtest/gtest.h>
#include "Truck.h"

TEST(TruckTest, TruckCarTypeNameTest)
{
	Truck truck{};
	EXPECT_EQ("Truck", truck.GetCarTypeName());
}