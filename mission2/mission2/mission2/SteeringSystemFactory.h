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
};

