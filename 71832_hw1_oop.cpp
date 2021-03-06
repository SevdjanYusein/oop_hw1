// 71832_hw1_oop.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "Vector.cpp"
#include "GalacticRepublic.h"
#include "String.h"

Vector<Galaxy> galaxies;

int getGalaxyInd(const String& galaxyName);
void findDominatingRepublic(const Vector<GalacticRepublic> republics, const String& galaxyName);
void writeGalaxiesToFile(const String& name);

int main()
{
	
	return 0;
}


int getGalaxyInd(const String& galaxyName)
{
	int pos = -1;
	for (int i = 0; i < galaxies.getCurrentCount(); i++)
	{
		if (galaxies[i].getName() == galaxyName)
		{
			pos = i;
			break;
		}
	}
	return pos;
}

void findDominatingRepublic(const Vector<GalacticRepublic> republics, const String& galaxyName)
{
	int galaxyInd = getGalaxyInd(galaxyName);
	if (galaxyInd == -1)
	{
		std::cout << "No such galaxy!!!\n";
		return;
	}
	if (galaxies[galaxyInd].getName() == galaxyName)
	{
		for (int i = 0; i < republics.getCurrentCount(); i++)
		{
			if (republics[i].getArmyCount() < republics[i].getJediCount())
			{
				if (galaxies[galaxyInd].isDominatedByRepublic(republics[i].getName()) == true)
				{
					std::cout << republics[i].getName() << std::endl;
					return;
				}
			}
		}
		std::cout << "No dominating republic!!\n";
	}
}

void writeGalaxiesToFile(const String& name)
{
	std::ofstream file("result.txt");
	for (int i = 0; i < galaxies.getCurrentCount(); i++)
	{
		file << galaxies[i].getName() << " - " << galaxies[i].getDominatingRepublic() << "\n";
	}
	file.close();
}