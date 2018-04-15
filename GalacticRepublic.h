#pragma once
#include "String.h"
#include "Galaxy.h"
#include "Army.h"
#include "JediTemple.h"


//Да се направи клас GalacticRepublic в който да има име на републиката,
//jediTemple(JediTemple), Army(Stormtrooper), galaxy(Galaxy).

class GalacticRepublic
{
private:
	String name;
	JediTemple jediTemple;
	Army army;
	Galaxy galaxy;
public:
	String getDominatingRepublic()const;
	void AddPlanet(const Planet& _planet);
	void AddSystem(const PlanetSystem& _system);
	int getJediCount()const { return jediTemple.getJediCount(); }
	int getArmyCount()const { return army.getCount(); }
	String getName()const { return name; }
	String getGalaxyName()const { return galaxy.getName(); }

};