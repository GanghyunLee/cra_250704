#pragma once
#include "AbstractEngine.h"

class GmEngine : public AbstractEngine
{
public:
	~GmEngine() override = default;

	std::string GetEngineName() override { return "GM"; }
};

