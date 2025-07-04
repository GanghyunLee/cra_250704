#include <gtest/gtest.h>
#include "BoschBrake.h"
#include "BrakeSystemFactory.h"
#include "ContinentalBrake.h"
#include "MandoBrake.h"

TEST(BrakeSystemFactoryTest, GivenMandoBrakeType_ThenMustReturnMandoBrakeType)
{
	EXPECT_NE(nullptr, std::dynamic_pointer_cast<MandoBrake>(BrakeSystemFactory::CreateBrakeSystem(BrakeSystem::MANDO)));
}

TEST(BrakeSystemFactoryTest, GivenContinentalBrakeType_ThenMustReturnContinentalBrakeType)
{
	EXPECT_NE(nullptr, std::dynamic_pointer_cast<ContinentalBrake>(BrakeSystemFactory::CreateBrakeSystem(BrakeSystem::CONTINENTAL)));
}

TEST(BrakeSystemFactoryTest, GivenBoscheBrakeType_ThenMustReturnBoscheBrakeType)
{
	EXPECT_NE(nullptr, std::dynamic_pointer_cast<BoschBrake>(BrakeSystemFactory::CreateBrakeSystem(BrakeSystem::BOSCH_B)));
}

TEST(BrakeSystemFactoryTest, GivenInvalidCarType_ThenMustReturnNullPtr)
{
	EXPECT_EQ(nullptr, BrakeSystemFactory::CreateBrakeSystem(static_cast<BrakeSystem>(0)));
	EXPECT_EQ(nullptr, BrakeSystemFactory::CreateBrakeSystem(static_cast<BrakeSystem>(4)));
}