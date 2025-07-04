#pragma once
#include <string>

class ICarComponent
{
public:
	virtual ~ICarComponent() = default;

public:
	virtual std::string GetComponentName() = 0;
};

