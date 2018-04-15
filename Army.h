#pragma once
#include <iostream>
#include <fstream>
#include "Stormtrooper.h"
#include "Vector.cpp"

class Army
{
private:
	Vector<Stormtrooper> troops;
public:
	void printStormtroopers();
	void printStormtroopersFromPlanet(std::ostream&, const Planet& planet);
	int  getCount()const;
	void addStormtrooper(const Stormtrooper& _stormtrooper);
};