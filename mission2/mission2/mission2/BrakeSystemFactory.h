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

    static bool ValidateUserInputIndex(int brakeTypeNumber) { return brakeTypeNumber >= GetMinInput() && brakeTypeNumber <= GetMaxInput(); }

    static int GetMinInput() { return MANDO; }
    static int GetMaxInput() { return BOSCH_B; }

    static std::string EnumeratesCatalogs();
};

