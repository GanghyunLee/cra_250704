#pragma once
#include "AbstractBrakeSystem.h"

class ContinentalBrake : public AbstractBrakeSystem
{
public:
	~ContinentalBrake() override = default;

public:
	std::string GetBrakeSystemName() override { return "CONTINENTAL"; }
};
