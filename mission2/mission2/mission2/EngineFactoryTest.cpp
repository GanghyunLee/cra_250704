#include <gtest/gtest.h>

#include "BrokenEngine.h"
#include "EngineFactory.h"
#include "GmEngine.h"
#include "ToyotaEngine.h"
#include "WiaEngine.h"

TEST(EngineFactoryTest, GivenGmEngineType_ThenMustReturnGmEngineType)
{
	EXPECT_NE(nullptr, std::dynamic_pointer_cast<GmEngine>(EngineFactory::CreateEngine(Engine::GM)));
}

TEST(EngineFactoryTest, GivenToyotaEngineType_ThenMustReturnToyotaEngineType)
{
	EXPECT_NE(nullptr, std::dynamic_pointer_cast<ToyotaEngine>(EngineFactory::CreateEngine(Engine::TOYOTA)));
}

TEST(EngineFactoryTest, GivenWiaEngineType_ThenMustReturnWiaEngineType)
{
	EXPECT_NE(nullptr, std::dynamic_pointer_cast<WiaEngine>(EngineFactory::CreateEngine(Engine::WIA)));
}

TEST(EngineFactoryTest, GivenBrokenEngineType_ThenMustReturnBrokenEngineType)
{
	EXPECT_NE(nullptr, std::dynamic_pointer_cast<BrokenEngine>(EngineFactory::CreateEngine(Engine::BROKEN)));
}

TEST(EngineFactoryTest, GivenInvalidCarType_ThenMustReturnNullPtr)
{
	EXPECT_EQ(nullptr, EngineFactory::CreateEngine(static_cast<Engine>(0)));
	EXPECT_EQ(nullptr, EngineFactory::CreateEngine(static_cast<Engine>(5)));
}