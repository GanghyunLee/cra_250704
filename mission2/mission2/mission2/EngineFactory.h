#pragma once
#include <memory>
#include "AbstractEngine.h"

enum Engine
{
    GM = 1,
    TOYOTA,
    WIA,
    BROKEN,
};

class EngineFactory
{
public:
    EngineFactory() = delete;

public:
    static std::shared_ptr<AbstractEngine> CreateEngine(Engine engine);

    static bool ValidateUserInputIndex(int engineTypeNumber) { return engineTypeNumber >= GetMinInput() && engineTypeNumber <= GetMaxInput(); }

    static int GetMinInput() { return GM; }
    static int GetMaxInput() { return BROKEN; }

    static std::string EnumeratesCatalogs();
};

