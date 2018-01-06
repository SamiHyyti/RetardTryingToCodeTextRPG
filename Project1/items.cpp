#include "item.h"
#include "items.h"
#include <fstream>
#include <iostream>
#include <ostream>
using namespace std;
vector<item> items;
vector<unsigned int> itemIndex;
void choise(int x)
{

}

void createItems()
{
	createWeapon("Katana","Beste Sword",200,1,10.f);
	createWeapon("Claymore", "Bigge Sword", 300, 2, 15.f);
	createArmor("Chainmail", "Protective armor made out of metal rings", 250, 3, 5);
	createAmulet("Amulet Of Health", "It has vitality enhancing properties", 350, 4, 0, 50.f, 0.f);
}



void createWeapon(string n, string d, int p, int id, float atk)
{
	weapon Weapon(n, d, p, id, atk);
	items.push_back(Weapon);
}
void createArmor(string n, string d, int p, int id, int def)
{
	armor Armor(n, d, p, id, def);
	items.push_back(Armor);
}
void createAmulet(string n, string d, int p, int id,int def, float hp, float atk)
{
	amulet Amulet(n, d, p, id, def, hp, atk);
	items.push_back(Amulet);
}

void print()
{	
	unsigned int x = 0;
	if (!items.empty())
	{
		for (; x != items.size(); x++)
		{
			itemIndex.push_back(x);
		}
		for (unsigned int z = 0; z != items.size(); z++)
		{
			//cout << itemIndex[z] + 1 << ". ";
			items[z].readName();
		}
	}

}

void inspect(int x)
{
	if (x < items.size())
		items[x].readItem();
	else
		cout << "error\n";
}