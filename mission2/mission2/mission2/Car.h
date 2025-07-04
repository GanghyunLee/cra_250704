#pragma once
#include <memory>

#include "AbstractBrakeSystem.h"
#include "AbstractCarType.h"
#include "AbstractEngine.h"
#include "AbstractSteering.h"

class Car
{
public:
	Car(const std::shared_ptr<AbstractCarType>& car_type, const std::shared_ptr<AbstractBrakeSystem>& brake_system,
		const std::shared_ptr<AbstractEngine>& engine, const std::shared_ptr<AbstractSteering>& steering)
		: _carType(car_type),
		  _brakeSystem(brake_system),
		  _engine(engine),
		  _steering(steering)
	{
	}

	std::shared_ptr<AbstractSteering> steering() const
	{
		return _steering;
	}

	std::shared_ptr<AbstractCarType> car_type() const
	{
		return _carType;
	}
	std::shared_ptr<AbstractBrakeSystem> brake_system() const
	{
		return _brakeSystem;
	}
	std::shared_ptr<AbstractEngine> engine() const
	{
		return _engine;
	}

private:
	std::shared_ptr<AbstractCarType>		_carType;
	std::shared_ptr<AbstractBrakeSystem>	_brakeSystem;
	std::shared_ptr<AbstractEngine>			_engine;
	std::shared_ptr<AbstractSteering>		_steering;
};

