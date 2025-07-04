#pragma once
#include <memory>
#include "AbstractSteering.h"

enum SteeringSystem
{
    BOSCH_S = 1,
    MOBIS,
};

class SteeringSystemFactory
{
public:
    SteeringSystemFactory() = delete;

public:
    static std::shared_ptr<AbstractSteering> CreateSteering(SteeringSystem steering);

    static bool ValidateUserInputIndex(int steeringNumber) { return steeringNumber >= GetMinInput() && steeringNumber <= GetMaxInput(); }

    static int GetMinInput() { return BOSCH_S; }
    static int GetMaxInput() { return MOBIS; }

    static std::string EnumeratesCatalogs();
};

