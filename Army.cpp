#include "Army.h"



void Army::printStormtroopers()
{
	std::ofstream fo("stormtroopers.txt");
	for (int i = 0; i < troops.getCurrentCount(); i++)
	{
		{
			fo << troops[i]
				<< std::endl;
		}
	}
	fo.close();
}

void Army::printStormtroopersFromPlanet(std::ostream& out, const Planet & planet)
{
	for (int i = 0; i < troops.getCurrentCount(); i++)
	{
		if (troops[i].getPlanet() == planet.getName())
		{
			out << troops[i]
				<< std::endl;
		}
	}
}

int Army::getCount() const
{
	return troops.getCurrentCount();
}

void Army::addStormtrooper(const Stormtrooper & _stormtrooper)
{
	if (troops.contains(_stormtrooper) == false)
	{
		troops.pushBack(_stormtrooper);
	}
}
