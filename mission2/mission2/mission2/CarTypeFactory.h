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
    static bool ValidateUserInputIndex(int carTypeNumber) { return carTypeNumber >= GetMinInput() && carTypeNumber <= GetMaxInput();  }

    static int GetMinInput() { return SEDAN; }
    static int GetMaxInput() { return TRUCK; }

    static std::string EnumeratesCatalogs();
};

