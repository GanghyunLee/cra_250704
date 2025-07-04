#pragma once
#include "AbstractBrakeSystem.h"

class MandoBrake : public AbstractBrakeSystem
{
public:
	~MandoBrake() override = default;

public:
	std::string GetBrakeSystemName() override { return "MANDO"; }
};

