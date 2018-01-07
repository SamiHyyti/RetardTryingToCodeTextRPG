#include "includes.h"
#include "items.h"
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
		cls();
		for (; x != items.size(); x++)
		{
			itemIndex.push_back(x);
		}
		for (unsigned int z = 0; z != items.size(); z++)
		{
			cout << itemIndex[z] + 1 << ". ";
			items[z].readName();
		}
	}
}

void inspect()
{
	int x;
	while (!(cin >> x))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		Sleep(100);
		cls();
	}
	x--;
	if (x < items.size())
	{
		int y;
		retry:
		cls();
		cout << "You have selected: ";
		items[x].readName();
		cout << "\n1. Purchase\n2. Inspect\n3. Back\n\nSelection: ";
		while (!(cin >> y))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cls();
			Sleep(100);
		}
		switch(y)
		{ 
			case 1:
				goto retry;
			case 2:
				cls();
				items[x].readItem();
				pause
				goto retry;
			case 3:
				return;
			default:
				goto retry;
		}
	}
	else
		cout << "error\n";
}