#include "EngineFactory.h"

#include <sstream>

#include "BrokenEngine.h"
#include "GmEngine.h"
#include "ToyotaEngine.h"
#include "WiaEngine.h"

std::shared_ptr<AbstractEngine> EngineFactory::CreateEngine(Engine engine)
{
	switch (engine)
	{
	case GM:
		return std::make_shared<GmEngine>();
	case TOYOTA:
		return std::make_shared<ToyotaEngine>();
	case WIA:
		return std::make_shared<WiaEngine>();
	case BROKEN:
		return std::make_shared<BrokenEngine>();
	}

	return nullptr;
}

std::string EngineFactory::EnumeratesCatalogs()
{
	std::stringstream ss;
	for (int i = GetMinInput(); i <= GetMaxInput(); i++)
	{
		ss << i << ". " << CreateEngine(static_cast<Engine>(i))->GetEngineName() << "\n";
	}

	return ss.str();
}
