#pragma once
#include "AbstractEngine.h"

class ToyotaEngine : public AbstractEngine
{
public:
	~ToyotaEngine() override = default;

	std::string GetEngineName() override { return "TOYOTA"; }
};