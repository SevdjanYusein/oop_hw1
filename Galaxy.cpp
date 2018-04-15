#include "Galaxy.h"

bool Galaxy::containsSystem(const String & _name)
{
	for (int i = 0; i < systems.getCurrentCount(); i++)
	{
		if (systems[i].getSystemName() == _name) return true;
	}
	return false;
}

void Galaxy::printPlanetsToFile()
{
	for (int i = 0; i < systems.getCurrentCount(); i++)
	{
		systems[i].printPlanetsToFile();
	}

}

void Galaxy::printPlanets()const
{
	for (int i = 0; i < systems.getCurrentCount(); i++)
	{
		systems[i].printPlanets();
	}
}

bool Galaxy::isDominatedByRepublic(const String & republic) const
{
	int dominatedSystems = 0;
	int countCountOfSystems= systems.getCurrentCount();
	for (int i = 0; i < countCountOfSystems; i++)
	{
		if (systems[i].getDominator()==republic) dominatedSystems++;
	}
	if (dominatedSystems > countCountOfSystems / 2) return true;
	return false;
}

String Galaxy::getDominatingRepublic() const
{
	struct RepublicDominons
	{
		String name;
		int count = 0;
		RepublicDominons(const String& _name="") { name = _name; }
		bool operator< (const RepublicDominons& _other)
		{
			if (count < _other.count) return true;
			return false;
		}
	};

	Vector<RepublicDominons> dominions;
	for (int i = 0; i < systems.getCurrentCount(); i++)
	{
		for (int j = 0; j < dominions.getCurrentCount(); j++)
		{
			if (dominions[i].name == systems[j].getDominator())
			{
				dominions[i].count++;
			}
			else
			{
				dominions.pushBack(RepublicDominons(systems[j].getDominator()));
			}
		}
	}
	dominions.sort();

	return dominions[0].name;
}

void Galaxy::addSystem(const String & _name)
{
	if ((bool)containsSystem(_name) == false) systems.pushBack(PlanetSystem(_name));
}

void Galaxy::addPlanet(const Planet & _planet)
{
	int systemInd = -1;
	for (int i = 0; i < systems.getCurrentCount(); i++)
	{
		if (systems[i].getSystemName() == _planet.getPlanetSystem())
		{
			systemInd = i;
			break;
		}
	}
	if (systemInd==-1)
	{
		addSystem(_planet.getPlanetSystem());
		systemInd = systems.getCurrentCount() - 1;
	}
	systems[systemInd].addPlanet(_planet);

}

void Galaxy::addSystem(const PlanetSystem & _system)
{
	if (systems.contains(_system) == false) systems.pushBack(_system);
}
