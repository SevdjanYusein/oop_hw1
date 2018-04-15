#pragma once
#include <iostream>
#include <fstream>
#include "Jedi.h"
#include "Vector.cpp"

class JediTemple
{
private:
	Vector<Jedi> jedi;
public:
	void printJedi();
	void printJediFromPlanet(std::ostream&, const Planet& planet);
	int  getJediCount() const { return jedi.getCurrentCount(); }
	void addJedi(const Jedi& _jedi);
};
