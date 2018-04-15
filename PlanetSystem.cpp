#include"PlanetSystem.h"

void PlanetSystem::DetermineDominatingRepublic(const String& _republic)
{
	if (isDominatedBy(_republic) == true) dominatingRepublic = _republic;
}

PlanetSystem::PlanetSystem(const String& _name) 
{ 
	systemName = _name; 
	dominatingRepublic = "None";
}

bool PlanetSystem::isDominatedBy(const String& republic)const
{
	int dominatedPlanets = 0;
	int countOfPlanets = planets.getCurrentCount();
	for (int i = 0; i < countOfPlanets; i++)
	{
		if (planets[i].getRepublic() == republic) dominatedPlanets++;
	}
	if (dominatedPlanets > 3 && dominatedPlanets > countOfPlanets / 2) return true;
	return false;
}

String PlanetSystem::getDominator()const
{
	return dominatingRepublic;
}

void PlanetSystem::printPlanetsToFile()const
{
	std::ofstream fo("planets.txt");
	for (int i = 0; i < planets.getCurrentCount(); i++)
	{
		fo << planets[i]
			<< std::endl;
	}
	fo.close();
}

void PlanetSystem::printPlanets() const
{
	for (int i = 0; i < planets.getCurrentCount(); i++)
	{
		std::cout << planets[i] << std::endl;
	}
}

int PlanetSystem::getPlanetsCount()const 
{ 
	return planets.getCurrentCount();
}

void PlanetSystem::addPlanet(const Planet& planet)
{
	if (planets.contains(planet) == false)
	{
		planets.pushBack(planet);
		DetermineDominatingRepublic(planet.getRepublic());
	}
}

String PlanetSystem::getSystemName()const 
{ 
	return systemName;
}

bool PlanetSystem::operator==(const PlanetSystem & _system)
{
	if (*this == _system) return true;
	return false;
}
