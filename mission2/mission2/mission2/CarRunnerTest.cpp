#include <gtest/gtest.h>

#include "BrakeSystemFactory.h"
#include "CarRunner.h"
#include "CarTypeFactory.h"
#include "EngineFactory.h"
#include "SteeringSystemFactory.h"

TEST(CarRunnerTest, SedanCannotHaveContinentalBreak)
{
	std::shared_ptr<Car> car = std::make_shared<Car>(
		CarTypeFactory::CreateCarType(CarType::SEDAN),
		BrakeSystemFactory::CreateBrakeSystem(BrakeSystem::CONTINENTAL),
		EngineFactory::CreateEngine(Engine::TOYOTA),
		SteeringSystemFactory::CreateSteering(SteeringSystem::MOBIS)
	);
	CarRunner carRunner{car};

	EXPECT_THROW(carRunner.ValidateCar(), std::exception);
}

TEST(CarRunnerTest, SuvCannotHaveToyotaEngine)
{
	std::shared_ptr<Car> car = std::make_shared<Car>(
		CarTypeFactory::CreateCarType(CarType::SUV),
		BrakeSystemFactory::CreateBrakeSystem(BrakeSystem::CONTINENTAL),
		EngineFactory::CreateEngine(Engine::TOYOTA),
		SteeringSystemFactory::CreateSteering(SteeringSystem::MOBIS)
	);
	CarRunner carRunner{ car };
	EXPECT_THROW(carRunner.ValidateCar(), std::exception);
}

TEST(CarRunnerTest, TruckCannotHaveWiaEngine)
{
	std::shared_ptr<Car> car = std::make_shared<Car>(
		CarTypeFactory::CreateCarType(CarType::TRUCK),
		BrakeSystemFactory::CreateBrakeSystem(BrakeSystem::CONTINENTAL),
		EngineFactory::CreateEngine(Engine::WIA),
		SteeringSystemFactory::CreateSteering(SteeringSystem::MOBIS)
	);
	CarRunner carRunner{ car };
	EXPECT_THROW(carRunner.ValidateCar(), std::exception);
}

TEST(CarRunnerTest, TruckCannotHaveMandoBrake)
{
	std::shared_ptr<Car> car = std::make_shared<Car>(
		CarTypeFactory::CreateCarType(CarType::TRUCK),
		BrakeSystemFactory::CreateBrakeSystem(BrakeSystem::MANDO),
		EngineFactory::CreateEngine(Engine::TOYOTA),
		SteeringSystemFactory::CreateSteering(SteeringSystem::MOBIS)
	);
	CarRunner carRunner{ car };
	EXPECT_THROW(carRunner.ValidateCar(), std::exception);
}

TEST(CarRunnerTest, BoschBrakeMustHaveBoschSteeringIfNotThrowsException)
{
	std::shared_ptr<Car> car = std::make_shared<Car>(
		CarTypeFactory::CreateCarType(CarType::TRUCK),
		BrakeSystemFactory::CreateBrakeSystem(BrakeSystem::BOSCH_B),
		EngineFactory::CreateEngine(Engine::TOYOTA),
		SteeringSystemFactory::CreateSteering(SteeringSystem::MOBIS)
	);
	CarRunner carRunner{ car };
	EXPECT_THROW(carRunner.ValidateCar(), std::exception);
}

TEST(CarRunnerTest, BoschBrakeMustHaveBoschSteering)
{
	std::shared_ptr<Car> car = std::make_shared<Car>(
		CarTypeFactory::CreateCarType(CarType::TRUCK),
		BrakeSystemFactory::CreateBrakeSystem(BrakeSystem::BOSCH_B),
		EngineFactory::CreateEngine(Engine::TOYOTA),
		SteeringSystemFactory::CreateSteering(SteeringSystem::BOSCH_S)
	);
	CarRunner carRunner{ car };
	EXPECT_NO_THROW(carRunner.ValidateCar());
}

TEST(CarRunnerTest, RunCarTestForNonBrokenEngine)
{
	const std::string expected = "Car Type : Sedan\nEngine : TOYOTA\nBrake System : CONTINENTAL\nSteeringSystem : MOBIS\n자동차가 동작됩니다.\n";

	std::shared_ptr<Car> car = std::make_shared<Car>(
		CarTypeFactory::CreateCarType(CarType::SEDAN),
		BrakeSystemFactory::CreateBrakeSystem(BrakeSystem::CONTINENTAL),
		EngineFactory::CreateEngine(Engine::TOYOTA),
		SteeringSystemFactory::CreateSteering(SteeringSystem::MOBIS)
	);
	CarRunner carRunner{ car };
	EXPECT_EQ(expected, carRunner.RunCar());
}

TEST(CarRunnerTest, RunCarTestForBrokenEngine)
{
	const std::string expected = "엔진이 고장나있습니다.\n자동차가 움직이지 않습니다.\n";

	std::shared_ptr<Car> car = std::make_shared<Car>(
		CarTypeFactory::CreateCarType(CarType::SEDAN),
		BrakeSystemFactory::CreateBrakeSystem(BrakeSystem::CONTINENTAL),
		EngineFactory::CreateEngine(Engine::BROKEN),
		SteeringSystemFactory::CreateSteering(SteeringSystem::MOBIS)
	);
	CarRunner carRunner{ car };
	EXPECT_EQ(expected, carRunner.RunCar());
}