#include "CarTypeFactory.h"

#include "Sedan.h"
#include "Suv.h"
#include "Truck.h"

std::shared_ptr<AbstractCarType> CarTypeFactory::CreateCarType(CarType carType)
{
	switch (carType)
	{
	case CarType::SEDAN:
		return std::make_shared<Sedan>();
	case CarType::SUV:
		return std::make_shared<Suv>();
	case CarType::TRUCK:
		return std::make_shared<Truck>();
	}

	return nullptr;
}
