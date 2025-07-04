#pragma once
#include "AbstractCarType.h"

class Suv : public AbstractCarType
{
public:
	~Suv() override = default;

public:

	std::string GetCarTypeName() override { return "Suv"; }
};
