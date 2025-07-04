#pragma once
#include <memory>
#include "AbstractCarType.h"

enum class CarType : uint8_t
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
	std::shared_ptr<AbstractCarType> CreateCarType(CarType carType);
};

