#pragma once
#include "ICarComponent.h"

class AbstractEngine : public ICarComponent
{
public:
	virtual ~AbstractEngine() = default;

public:
	virtual std::string GetEngineName() = 0;
	std::string GetComponentName() override { return "엔진"; }
};

