#pragma once
#include<fstream>
#include"Vector.cpp"
#include"String.h"
#include"Planet.h"


class PlanetSystem
{
private:
	Vector<Planet> planets;
	String systemName;
	String dominatingRepublic;

	void DetermineDominatingRepublic(const String& _republic);
public:
	PlanetSystem(const String& _name = "NoName");
	bool isDominatedBy(const String& republic)const;
	String getDominator()const;
	void printPlanetsToFile()const;
	void printPlanets() const;
	int getPlanetsCount()const;
	void addPlanet(const Planet& planet);
	String getSystemName()const;
	bool operator==(const PlanetSystem& _system);
};
