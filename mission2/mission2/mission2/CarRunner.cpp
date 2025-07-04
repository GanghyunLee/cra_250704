#include "CarRunner.h"
#include <sstream>

#include "BoschBrake.h"
#include "BoschSteering.h"
#include "ContinentalBrake.h"
#include "MandoBrake.h"
#include "Sedan.h"
#include "Suv.h"
#include "ToyotaEngine.h"
#include "Truck.h"
#include "WiaEngine.h"

void CarRunner::ValidateCar()
{
	std::string errMsg;

	std::shared_ptr<AbstractCarType> carType = _car->car_type();
	std::shared_ptr<AbstractBrakeSystem> brakeSystem = _car->brake_system();
	std::shared_ptr<AbstractEngine> engine = _car->engine();
	std::shared_ptr<AbstractSteering> steering = _car->steering();

	if (nullptr != std::dynamic_pointer_cast<Sedan>(carType))
	{
		if (nullptr != std::dynamic_pointer_cast<ContinentalBrake>(brakeSystem))
		{
			std::stringstream ss;
			ss << carType->GetCarTypeName() << "에는 ";
			ss << brakeSystem->GetBrakeSystemName() << " ";
			ss << brakeSystem->GetComponentName() << " 사용 불가";
			errMsg = ss.str();
		}
	}
	else if (nullptr != std::dynamic_pointer_cast<Suv>(carType))
	{
		if (nullptr != std::dynamic_pointer_cast<ToyotaEngine>(engine))
		{
			std::stringstream ss;
			ss << carType->GetCarTypeName() << "에는 ";
			ss << engine->GetEngineName() << " ";
			ss << engine->GetComponentName() << " 사용 불가";
			errMsg = ss.str();
		}
	}
	else if (nullptr != std::dynamic_pointer_cast<Truck>(carType))
	{
		if (nullptr != std::dynamic_pointer_cast<WiaEngine>(engine))
		{
			std::stringstream ss;
			ss << carType->GetCarTypeName() << "에는 ";
			ss << engine->GetEngineName() << " ";
			ss << engine->GetComponentName() << " 사용 불가";
			errMsg = ss.str();
		}
		else if (nullptr != std::dynamic_pointer_cast<MandoBrake>(brakeSystem))
		{
			std::stringstream ss;
			ss << carType->GetCarTypeName() << "에는 ";
			ss << brakeSystem->GetBrakeSystemName() << " ";
			ss << brakeSystem->GetComponentName() << " 사용 불가";
			errMsg = ss.str();
		}
	}

	if (nullptr != std::dynamic_pointer_cast<BoschBrake>(brakeSystem))
	{
		if (nullptr == std::dynamic_pointer_cast<BoschSteering>(steering))
		{
			std::stringstream ss;
			ss << brakeSystem->GetBrakeSystemName() << "에는 ";
			ss << steering->GetSteeringName() << " ";
			ss << steering->GetComponentName() << " 이외 사용 불가";
			errMsg = ss.str();
		}
	}

	if (false == errMsg.empty()) // for 100% coverage
		throw std::exception{ errMsg.c_str() };
}

std::string CarRunner::RunCar()
{
	std::stringstream runResultStringStream;

	if (IsEngineBroken())
	{
		runResultStringStream << "엔진이 고장나있습니다.\n";
		runResultStringStream << "자동차가 움직이지 않습니다.\n";
	}
	else
	{
		runResultStringStream << "Car Type : " << _car->car_type()->GetCarTypeName() << "\n";
		runResultStringStream << "Engine : " << _car->engine()->GetEngineName() << "\n";
		runResultStringStream << "Brake System : " << _car->brake_system()->GetBrakeSystemName() << "\n";
		runResultStringStream << "SteeringSystem : " << _car->steering()->GetSteeringName() << "\n";
		runResultStringStream << "자동차가 동작됩니다." << "\n";
	}

	return runResultStringStream.str();
}
