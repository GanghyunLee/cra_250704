#include "EngineFactory.h"
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
