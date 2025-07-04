#include "CarTypeFactory.h"

#include <sstream>

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

std::string CarTypeFactory::EnumeratesCatalogs()
{
	std::stringstream ss;
	for (int i = GetMinInput(); i <= GetMaxInput(); i++)
	{
		ss << i << ". " << CreateCarType(static_cast<CarType>(i))->GetCarTypeName() << "\n";
	}

	return ss.str();
}
