#include "GalacticRepublic.h"

String GalacticRepublic::getDominatingRepublic() const
{
	return galaxy.getDominatingRepublic();
}

void GalacticRepublic::AddPlanet(const Planet& _planet)
{
	galaxy.addPlanet(_planet);
}

void GalacticRepublic::AddSystem(const PlanetSystem& _system)
{
	galaxy.addSystem(_system);
}
