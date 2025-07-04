﻿#pragma once
#include "ICarComponent.h"

class AbstractSteering : public ICarComponent
{
public:
	virtual ~AbstractSteering() = default;

public:
	virtual std::string GetSteeringName() = 0;
	std::string GetComponentName() override { return "조향장치"; }
};

