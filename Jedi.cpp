#include <cstring>
#include "Jedi.h"
#include "Planet.h"


Jedi::Jedi()
{
	rank = padawan;
	midi_chlorian = 0;
}

Jedi::Jedi(const Jedi & other)
{
	copy(other);
}

Jedi & Jedi::operator=(const Jedi & other)
{
	if (this != &other)
	{
		copy(other);
	}
	return *this;
}

String Jedi::getPlanet() const
{
	return planet.getName(); 
}

void Jedi::copy(const Jedi& other)
{
	name = other.name;
	rank = other.rank;
	midi_chlorian = other.midi_chlorian;
	planet = other.planet;
	spicies = other.spicies;
	militaryRank = other.militaryRank;
}

std::ostream& operator<<(std::ostream& out, const Jedi& jedi)
{
	out << jedi.name << std::endl
		<< jedi.rank << std::endl
		<< jedi.midi_chlorian << std::endl
		<< jedi.planet
		<< jedi.spicies << std::endl
		<< jedi.militaryRank << std::endl;
	return out;
}

bool Jedi::operator==(const Jedi& _jedi) const
{
	if (*this == _jedi) return true;
	return false;
}