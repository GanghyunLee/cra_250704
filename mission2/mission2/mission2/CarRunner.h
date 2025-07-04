#pragma once
#include <memory>

#include "BrokenEngine.h"
#include "Car.h"


class CarRunner
{
public:
	CarRunner(std::shared_ptr<Car> car) : _car(car)
	{
	}

public:
	void			ValidateCar();
	std::string		RunCar();

private:
	bool IsEngineBroken() { return nullptr != std::dynamic_pointer_cast<BrokenEngine>(_car->engine()); }

private:
	std::shared_ptr<Car> _car;
};

