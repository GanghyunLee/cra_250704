#pragma once
#include "ICarComponent.h"

class AbstractCarType : public ICarComponent
{
public:
	virtual ~AbstractCarType() = default;

public:
	virtual std::string GetCarTypeName() = 0;
	std::string GetComponentName() override { return "차량 타입";  }
};

