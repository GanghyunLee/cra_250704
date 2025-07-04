#pragma once
#include "AbstractSteering.h"

class BoschSteering : public AbstractSteering
{
public:
	~BoschSteering() override = default;

public:
	std::string GetEngineName() override { return "BOSCH"; }
};

