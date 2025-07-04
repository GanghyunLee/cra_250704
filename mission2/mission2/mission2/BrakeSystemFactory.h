#pragma once
#include <memory>
#include "AbstractBrakeSystem.h"

enum BrakeSystem
{
    MANDO = 1,
    CONTINENTAL,
    BOSCH_B,
};

class BrakeSystemFactory
{
public:
	BrakeSystemFactory() = delete;

public:
    static std::shared_ptr<AbstractBrakeSystem> CreateBrakeSystem(BrakeSystem brakeSystem);
};

