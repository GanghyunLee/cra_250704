#include "SteeringSystemFactory.h"
#include "BoschSteering.h"
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
