#include "SteeringSystemFactory.h"

#include <sstream>

#include "BoschSteering.h"
#include "BrakeSystemFactory.h"
#include "MobisSteering.h"

std::shared_ptr<AbstractSteering> SteeringSystemFactory::CreateSteering(SteeringSystem steering)
{
	switch (steering)
	{
	case BOSCH_S:
		return std::make_shared<BoschSteering>();
	case MOBIS:
		return std::make_shared<MobisSteering>();
	}
	return nullptr;
}

std::string SteeringSystemFactory::EnumeratesCatalogs()
{
	std::stringstream ss;
	for (int i = GetMinInput(); i <= GetMaxInput(); i++)
	{
		ss << i << ". " << CreateSteering(static_cast<SteeringSystem>(i))->GetSteeringName() << "\n";
	}

	return ss.str();
}
