#pragma once
#include "AbstractSteering.h"

class MobisSteering : public AbstractSteering
{
public:
	~MobisSteering() override = default;

public:
	std::string GetSteeringName() override { return "MOBIS"; }
};
