#pragma once
#include "AbstractEngine.h"

class BrokenEngine : public AbstractEngine
{
public:
	~BrokenEngine() override = default;

	std::string GetEngineName() override { return "고장난 엔진"; }
};