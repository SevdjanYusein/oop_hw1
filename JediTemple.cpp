#include "JediTemple.h"

void JediTemple::printJedi()
{
	std::ofstream fo("jedi.txt");
	for (int i = 0; i < jedi.getCurrentCount(); i++)
	{
		fo << jedi[i] << std::endl;
	}
	fo.close();
}

void JediTemple::printJediFromPlanet(std::ostream& out,const Planet & planet)
{
	for (int i = 0; i < jedi.getCurrentCount(); i++)
	{
		if (jedi[i].getPlanet() == planet.getName())
		{
			out << jedi[i]
				<< std::endl;
		}
	}
}

void JediTemple::addJedi(const Jedi & _jedi)
{
	if (jedi.contains(_jedi) == false)
	{
		jedi.pushBack(_jedi);
	}
}
