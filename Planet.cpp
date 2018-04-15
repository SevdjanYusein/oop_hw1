#include "Planet.h"
#include <cstring>

void Planet::copy(const Planet& other)
{
	name = other.name;
	planetSystem = other.planetSystem;
	republic = other.republic;
}


Planet::Planet()
{
	name;
	planetSystem;
	republic;
}

Planet::Planet(const Planet& other)
{
	if (this != &other)
	{
		copy(other);
	}
}


void Planet::operator=(const Planet& other)
{
	copy(other);
}

std::ostream& operator<< (std::ostream& out, const Planet& planet)
{
	out << planet.name << std::endl
		<< planet.planetSystem << std::endl
		<< planet.republic << std::endl;
	return out;
}

bool Planet::operator==(const Planet& _planet) const
{
	if (*this == _planet) return true;
	return false;
}