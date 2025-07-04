#include "BrakeSystemFactory.h"
#include "BoschBrake.h"
#include "ContinentalBrake.h"
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
