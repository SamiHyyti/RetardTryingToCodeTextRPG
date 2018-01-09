#include "includes.h"
#include "gamefunctions.h"
using namespace std;
float percentage = 0.f;
enemy Enemy;
player Player;
vector<item> items;
vector<unsigned int> itemIndex;
void choise(int x)
{
	
}
void combatMenu()
{
	bool menu = true;
	float x;
	cls();
	cout << "1. Strong Attack\n2. Normal Attack\n3. Quick Attack\n";
	while (menu == true)
	{
		_getch();
		if (GetAsyncKeyState(VK_KEY_1) & 0x8000 || GetAsyncKeyState(VK_NUMPAD1) & 0x8000)
		{
			x = Player.attack(1);
			if (x != 0)
				Enemy.takeDamage(x);
			else
				youmissed();
			menu = false;
		}
		else if (GetAsyncKeyState(VK_KEY_2) & 0x8000 || GetAsyncKeyState(VK_NUMPAD2) & 0x8000)
		{
			x = Player.attack(2);
			if (x != 0)
				Enemy.takeDamage(x);
			else
				youmissed();
			menu = false;
		}
		else if (GetAsyncKeyState(VK_KEY_3) & 0x8000 || GetAsyncKeyState(VK_NUMPAD3) & 0x8000)
		{
			x = Player.attack(3);
			if (x != 0)
				Enemy.takeDamage(x);
			else
				youmissed();
			menu = false;
		}
	}
}

void adventureMenu()
{
	string selectiontext = "1. battle random enemy\n2. current stats and equipment\n3. shop(TEST PHASE)\n4. quit\n";
retry:
	cout << selectiontext;
	while (1)
	{
		_getch();
		if (GetAsyncKeyState(VK_KEY_1) & 0x8000 || GetAsyncKeyState(VK_NUMPAD1) & 0x8000)
		{
			generateEnemy();
			Sleep(100);
			battle();
			goto retry;
		}
		else if (GetAsyncKeyState(VK_KEY_2) & 0x8000 || GetAsyncKeyState(VK_NUMPAD2) & 0x8000)
		{
			Player.readStats();
			goto retry;
		}
		else if (GetAsyncKeyState(VK_KEY_3) & 0x8000 || GetAsyncKeyState(VK_NUMPAD3) & 0x8000)
		{
			shop();
			cls();
			goto retry;
		}
		else if (GetAsyncKeyState(VK_KEY_4) & 0x8000 || GetAsyncKeyState(VK_NUMPAD4) & 0x8000)
		{
			exit(2);
		}
	}

}

void shop()
{
	int selection;
	print();
	inspect();
	cls();
}

void characterCreation()
{
	cout << "Enter the name of your character: ";
	Player.giveName();
	cls();
	Player.chooseClass();
	cls();
	Player.creation();
}

void youmissed()
{
	cls();
	cout << "Your attack missed!\n";
	pause();
}

void enemymissed()
{
	cls();
	cout << "The enemy attack missed you!\n";
	pause();
}

void generateEnemy()
{
	int x = rand() % 100 + 1;
	if (x < 51)
	{
		Enemy.stats(10.f + 10.f * percentage, 0, 10.f, percentage, "Goblin");
	}
	else if (x < 81)
	{
		Enemy.stats(20.f + 20.f * percentage, 4, 15.f, percentage, "Orc");
	}
	else
	{
		Enemy.stats(50.f + 50.f * percentage, 10, 20.f, percentage, "Troll");
	}
}

void mainMenu()
{
	string menutext = "text monster killing RPG v0.18 early acces alpha\n\n1. New game\n2. Quit game\n";
	cout << menutext;
	while (1)
	{
		_getch();
		if (GetAsyncKeyState(VK_KEY_1) & 0x8000 || GetAsyncKeyState(VK_NUMPAD1) & 0x8000)
		{
			cls();
			return;
		}
		else if (GetAsyncKeyState(VK_KEY_2) & 0x8000 || GetAsyncKeyState(VK_NUMPAD2) & 0x8000)
		{
			exit(1);
		}
	}

}

void battle()
{
	bool menu = true;
retry:
	Enemy.readStats();
	cout << "\n\n1. Attack Enemy\n2. Flee the battle\n";
	while (menu == true)
	{
		_getch();
		if (GetAsyncKeyState(VK_KEY_1) & 0x8000 || GetAsyncKeyState(VK_NUMPAD1) & 0x8000)
		{
			combatMenu();
			if (Enemy.alive() > !0.0f)
			{
				float x;
				x = Enemy.attack();
				if (x != 0)
					Player.takeDamage(x);
				else
					enemymissed();
				if (Player.alive() > !0.0f)
					goto retry;
				else
				{
					cls();
					cout << "YOU DIED\nGAME OVER!\n";
					pause();
					exit(3);
				}
			}
			else if (Enemy.alive() > !0.0f)
				goto retry;
			else
			{
				menu = false;
				percentage += 0.01f;
			}
		}
		else if (GetAsyncKeyState(VK_KEY_2) & 0x8000 || GetAsyncKeyState(VK_NUMPAD2) & 0x8000)
		{
			menu = false;
			if (percentage != 0.00f)
			{
				percentage -= 0.01f;
				cls();
				break;
			}
			cls();
		}

	}
}

void createItems()
{
	createWeapon("Katana","Beste Sword",200,1,10.f);
	createWeapon("Claymore", "Bigge Sword", 300, 1, 15.f);
	createArmor("Chainmail", "Protective armor made out of metal rings", 250, 2, 5);
	createAmulet("Amulet Of Health", "It has vitality enhancing properties", 350, 3, 0, 50.f, 0.f);
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
	int x = -1;
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
		cout << "Price: " << items[x].receivePayment() << " $\n" << "Your Money: " << Player.offer() << " $\n";
		cout << "\n1. Purchase\n2. Inspect\n3. Back\n";
		while (1)
		{
			_getch();
			if (GetAsyncKeyState(VK_KEY_1) & 0x8000 || GetAsyncKeyState(VK_NUMPAD1) & 0x8000)
			{
				int payment = Player.offer();
				int price = items[x].receivePayment();
				if (payment < price)
				{
					cout << "You do not have enough money to buy that Goy.";
					Sleep(2500);
					goto retry;
				}
				else
				{
					Player.pay(price);
					Player.equip(items[x].checkID(), items[x].retHp(), items[x].retDmg(), items[x].retDef(), items[x].retNa(), items[x].retDe());
					cout << "Thank you for your purchase Goy.";
					Sleep(2500);
					return;
				}
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