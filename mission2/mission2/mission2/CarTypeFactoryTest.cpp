#include <gtest/gtest.h>
#include "CarTypeFactory.h"
#include "Sedan.h"
#include "Suv.h"
#include "Truck.h"

TEST(CarTypeFactoryTest, GivenSedanCarType_ThenMustReturnSedanType)
{
	EXPECT_NE(nullptr, std::dynamic_pointer_cast<Sedan>(CarTypeFactory::CreateCarType(CarType::SEDAN)));
}

TEST(CarTypeFactoryTest, GivenSuvCarType_ThenMustReturnSuvType)
{
	EXPECT_NE(nullptr, std::dynamic_pointer_cast<Suv>(CarTypeFactory::CreateCarType(CarType::SUV)));
}

TEST(CarTypeFactoryTest, GivenTruckCarType_ThenMustReturnTruckType)
{
	EXPECT_NE(nullptr, std::dynamic_pointer_cast<Truck>(CarTypeFactory::CreateCarType(CarType::TRUCK)));
}

TEST(CarTypeFactoryTest, GivenInvalidCarType_ThenMustReturnNullPtr)
{
	EXPECT_EQ(nullptr, CarTypeFactory::CreateCarType(static_cast<CarType>(0)));
	EXPECT_EQ(nullptr, CarTypeFactory::CreateCarType(static_cast<CarType>(4)));
}