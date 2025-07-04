#include "BrakeSystemFactory.h"

#include <sstream>

#include "BoschBrake.h"
#include "ContinentalBrake.h"
#include "EngineFactory.h"
#include "MandoBrake.h"

std::shared_ptr<AbstractBrakeSystem> BrakeSystemFactory::CreateBrakeSystem(BrakeSystem brakeSystem)
{
	switch (brakeSystem)
	{
	case MANDO:
		return std::make_shared<MandoBrake>();
	case CONTINENTAL:
		return std::make_shared<ContinentalBrake>();
	case BOSCH_B:
		return std::make_shared<BoschBrake>();
	}
	return nullptr;
}

std::string BrakeSystemFactory::EnumeratesCatalogs()
{
	std::stringstream ss;
	for (int i = GetMinInput(); i <= GetMaxInput(); i++)
	{
		ss << i << ". " << CreateBrakeSystem(static_cast<BrakeSystem>(i))->GetBrakeSystemName() << "\n";
	}

	return ss.str();
}
