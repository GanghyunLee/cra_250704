#pragma once
#include "AbstractCarType.h"

class Sedan : public AbstractCarType
{
public:
	~Sedan() override = default;

public:

	std::string GetCarTypeName() override { return "Sedan";  }
};

