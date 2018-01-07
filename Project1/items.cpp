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
	while (1)
	{
		_getch();
		if (GetAsyncKeyState(VK_KEY_1) & 0x8000 || GetAsyncKeyState(VK_NUMPAD1) & 0x8000)
		{
			x = 0;
		}
		else if (GetAsyncKeyState(VK_KEY_2) & 0x8000 || GetAsyncKeyState(VK_NUMPAD2) & 0x8000)
		{
			x = 1;
		}
		else if (GetAsyncKeyState(VK_KEY_3) & 0x8000 || GetAsyncKeyState(VK_NUMPAD3) & 0x8000)
		{
			x = 2;
		}
		else if (GetAsyncKeyState(VK_KEY_4) & 0x8000 || GetAsyncKeyState(VK_NUMPAD4) & 0x8000)
		{
			x = 3;
		}
		else if (GetAsyncKeyState(VK_KEY_5) & 0x8000 || GetAsyncKeyState(VK_NUMPAD5) & 0x8000)
		{
			x = 4;
		}
		else if (GetAsyncKeyState(VK_KEY_6) & 0x8000 || GetAsyncKeyState(VK_NUMPAD6) & 0x8000)
		{
			x = 5;
		}
		else if (GetAsyncKeyState(VK_KEY_7) & 0x8000 || GetAsyncKeyState(VK_NUMPAD7) & 0x8000)
		{
			x = 6;
		}
		else if (GetAsyncKeyState(VK_KEY_8) & 0x8000 || GetAsyncKeyState(VK_NUMPAD8) & 0x8000)
		{
			x = 7;
		}
		else if (GetAsyncKeyState(VK_KEY_9) & 0x8000 || GetAsyncKeyState(VK_NUMPAD9) & 0x8000)
		{
			x = 8;
		}
		if (x < items.size())
			break;
	}

	if (x < items.size())
	{
	retry:
		cls();
		cout << "You have selected: ";
		items[x].readName();
		cout << "\n1. Purchase\n2. Inspect\n3. Back\n";
		while (1)
		{
			_getch();
			if (GetAsyncKeyState(VK_KEY_1) & 0x8000 || GetAsyncKeyState(VK_NUMPAD1) & 0x8000)
			{
				goto retry;
			}
			else if (GetAsyncKeyState(VK_KEY_2) & 0x8000 || GetAsyncKeyState(VK_NUMPAD2) & 0x8000)
			{
				cls();
				items[x].readItem();
				pause();
				goto retry;
			}
			else if (GetAsyncKeyState(VK_KEY_3) & 0x8000 || GetAsyncKeyState(VK_NUMPAD3) & 0x8000)
			{
				return;
			}
		}
	}
}