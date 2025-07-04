#pragma once
#include "AbstractEngine.h"

class WiaEngine : public AbstractEngine
{
public:
	~WiaEngine() override = default;

	std::string GetEngineName() override { return "WIA"; }
};