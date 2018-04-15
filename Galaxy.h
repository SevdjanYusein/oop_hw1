#pragma once
#include <iostream>
#include <fstream>
#include "String.h"
#include "Planet.h"
#include "Vector.cpp"
#include "PlanetSystem.h"

class Galaxy
{
private:
	String name;
	Vector<PlanetSystem> systems;
	bool containsSystem(const String& _name);
public:
	int getSystemCount()const { return systems.getCurrentCount(); }
	void printPlanetsToFile();
	void printPlanets()const;
	bool isDominatedByRepublic(const String& republic)const;
	String getDominatingRepublic()const;
	String getName()const { return name; }
	void addSystem(const String& _name);
	void addPlanet(const Planet& _planet);
	void addSystem(const PlanetSystem& _system);
};