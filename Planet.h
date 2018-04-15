#pragma once
#include "String.h"

//Да се направи клас Planet name(char*), planetSystem(char*), republic(char*) - име на притежаващата я република.

class Planet
{
private:
	String name;
	String planetSystem;
	String republic;
	void copy(const Planet& other);
public:
	Planet();
	Planet(const Planet& other);
	void operator= (const Planet& other);
	const String getName() const { return name; }
	const String getPlanetSystem() const { return planetSystem; }
	const String getRepublic() const { return republic; }
	friend std::ostream& operator<< (std::ostream&, const Planet&);
	bool operator==(const Planet& _planet) const;
};

