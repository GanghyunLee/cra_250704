#pragma once
#include <memory>
#include "AbstractCarType.h"

enum CarType
{
    SEDAN = 1,
    SUV,
    TRUCK,
};

class CarTypeFactory
{
public:
	CarTypeFactory() = delete;

public:
	static std::shared_ptr<AbstractCarType> CreateCarType(CarType carType);
};

