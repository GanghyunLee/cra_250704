#pragma once
#include "ICarComponent.h"

class AbstractBrakeSystem : public ICarComponent
{
public:
	virtual ~AbstractBrakeSystem() = default;

public:
	virtual std::string GetBrakeSystemName() = 0;
	std::string GetComponentName() override { return "제동장치"; }
};

