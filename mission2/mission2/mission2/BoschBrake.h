#pragma once
#include "AbstractBrakeSystem.h"

class BoschBrake : public AbstractBrakeSystem
{
public:
	~BoschBrake() override = default;

public:
	std::string GetBrakeSystemName() override { return "BOSCH"; }
};
