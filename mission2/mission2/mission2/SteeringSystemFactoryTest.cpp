#include <gtest/gtest.h>

#include "BoschSteering.h"
#include "MobisSteering.h"
#include "SteeringSystemFactory.h"

TEST(SteeringSystemFactoryTest, GivenBoschSteeringType_ThenMustReturnBoschSteeringType)
{
	EXPECT_NE(nullptr, std::dynamic_pointer_cast<BoschSteering>(SteeringSystemFactory::CreateSteering(SteeringSystem::BOSCH_S)));
}

TEST(SteeringSystemFactoryTest, GivenMobisSteeringType_ThenMustReturnMobisSteeringType)
{
	EXPECT_NE(nullptr, std::dynamic_pointer_cast<MobisSteering>(SteeringSystemFactory::CreateSteering(SteeringSystem::MOBIS)));
}

TEST(SteeringSystemFactoryTest, EnumeratesCatalogsTest)
{
	const std::string expected = "1. BOSCH\n2. MOBIS\n";
	EXPECT_EQ(expected, SteeringSystemFactory::EnumeratesCatalogs());
}

TEST(SteeringSystemFactoryTest, GivenInvalidSteeringType_ThenMustReturnNullPtr)
{
	EXPECT_EQ(nullptr, SteeringSystemFactory::CreateSteering(static_cast<SteeringSystem>(0)));
	EXPECT_EQ(nullptr, SteeringSystemFactory::CreateSteering(static_cast<SteeringSystem>(3)));
}