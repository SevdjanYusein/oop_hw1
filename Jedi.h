#pragma once
#include <iostream>
#include <fstream>
#include "Planet.h"
#include "String.h"

//Да се направи клас Jedi в който да има name(char*), rank(char*/enum), 
//midi-chlorian(double/float), planet(Planet), spicies(char*), militaryRank(char*).

enum JediRank { padawan = 0, Grand_master = 1, Master = 2, Knight = 3 };


class Jedi
{
private:
	String name;
	JediRank rank;
	double midi_chlorian;
	Planet planet;
	String spicies;
	String militaryRank;
	void copy(const Jedi& other);
public:
	Jedi();
	Jedi(const Jedi& other);
	Jedi& operator= (const Jedi& other);
	String getPlanet()const;
	friend std::ostream& operator<<(std::ostream&, const Jedi&);
	bool operator==(const Jedi& _jedi) const;
};

