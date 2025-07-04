#pragma once
#include "AbstractSteering.h"

class BoschSteering : public AbstractSteering
{
public:
	~BoschSteering() override = default;

public:
	std::string GetSteeringName() override { return "BOSCH"; }
};

