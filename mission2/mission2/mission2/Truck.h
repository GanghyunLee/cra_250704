#pragma once
#include "AbstractCarType.h"

class Truck : public AbstractCarType
{
public:
	~Truck() override = default;

public:
	std::string GetCarTypeName() override { return "Truck"; }
};

