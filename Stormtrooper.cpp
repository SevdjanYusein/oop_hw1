#include "Stormtrooper.h"

void Stormtrooper::copy(const Stormtrooper & other)
{
	id = other.id;
	rank = other.rank;
	type = other.type;
	planet = other.planet;
}

Stormtrooper::Stormtrooper()
{
	rank = cadet;
}

Stormtrooper & Stormtrooper::operator=(const Stormtrooper & other)
{
	if (this != &other)
	{
		copy(other);
	}
	return *this;
}

String Stormtrooper::getPlanet() const
{
	return planet.getName();
}

String Stormtrooper::getID() const
{
	return id;
}

bool Stormtrooper::operator==(const Stormtrooper & _trooper) const
{
	if (*this == _trooper) return true;
	return false;
}



std::ostream& operator<< (std::ostream& out, const Stormtrooper& troop)
{
	out << troop.id << std::endl
		<< troop.rank << std::endl
		<< troop.type << std::endl
		<< troop.planet;
	return out;
}