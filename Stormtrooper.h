#pragma once
#include <iostream>
#include <fstream>
#include "String.h"
#include "Planet.h"

//Да се направи клас Stormtrooper в който да има id(char*), rank(enum), type(char*), planet(Planet).

enum StormtrooperRank { cadet = 0, magma_trooper = 1, rocket_stormtrooper = 2, demolition_trooper = 3, death_trooper = 4, shadow_trooper = 5 };

class Stormtrooper
{
private:
	String id;
	StormtrooperRank rank;
	String type;
	Planet planet;
	void copy(const Stormtrooper& other);
public:
	Stormtrooper();
	Stormtrooper& operator= (const Stormtrooper& other);
	String getPlanet()const;
	friend std::ostream& operator<< (std::ostream&, const Stormtrooper&);
	String getID()const;
	bool operator==(const Stormtrooper& _trooper)const;
};

