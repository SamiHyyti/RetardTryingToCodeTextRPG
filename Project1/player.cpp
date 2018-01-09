#include "includes.h"
using namespace std;

float player::alive()
{
	return health;
}
void player::creation()
{
	cls();
	cout << name << endl << "health: " << setprecision(2) << fixed << health << "/" << setprecision(0) << fixed << maxhealth + amuletHP << endl << "attack: " << atk + weaponAtk << endl << "defense: " << def + armorDef + amuletDef << endl << "shekels: " << shekels << endl;
	pause();
}
void player::readStats()
{
	stats:
	cls();
	cout << name << endl << "health: " << setprecision(2) << fixed << health << "/" << setprecision(0) << fixed << maxhealth + amuletHP << endl << "attack: " << atk + weaponAtk << endl << "defense: " << def + armorDef + amuletDef << endl << "shekels: " << shekels << endl;
	cout << "\n1. View your equipment\n2. Back";
	while (1)
	{
		_getch();
		if (GetAsyncKeyState(VK_KEY_1) & 0x8000 || GetAsyncKeyState(VK_NUMPAD1) & 0x8000)
		{
			equipment:
			cls();
			cout << "SUPER EPIC EQUIPMENT MENU\n\n1. Weapon:	" << weaponN << "\n2. Armor:	" << armorN << "\n3. Amulet:	" << amuletN << "\n4. Back";
			retry:
			while (1)
			{
				_getch();
				if (GetAsyncKeyState(VK_KEY_1) & 0x8000 || GetAsyncKeyState(VK_NUMPAD1) & 0x8000)
				{
					if (!weaponN.empty())
					{
						cls();
						cout << weaponN << endl << weaponDesc << "\nDamage: " << weaponAtk;
						pause();
						goto equipment;
					}
					else
					{
						cls();
						cout << "SUPER EPIC EQUIPMENT MENU\n\n1. Weapon:	You do not have weapon!!!" << weaponN << "\n2. Armor:	" << armorN << "\n3. Amulet:	" << amuletN << "\n4. Back";
						goto retry;
					}
				}
				else if (GetAsyncKeyState(VK_KEY_2) & 0x8000 || GetAsyncKeyState(VK_NUMPAD2) & 0x8000)
				{ 
					if (!armorN.empty())
					{
						cls();
						cout << armorN << endl << armorDesc << "\nArmor: " << armorDef;
						pause();
						goto equipment;
					}
					else
					{
						cls();
						cout << "SUPER EPIC EQUIPMENT MENU\n\n1. Weapon:	" << weaponN << "\n2. Armor:	You do not have armor!!!" << armorN << "\n3. Amulet:	" << amuletN << "\n4. Back";
						goto retry;
					}
				}
				else if (GetAsyncKeyState(VK_KEY_3) & 0x8000 || GetAsyncKeyState(VK_NUMPAD3) & 0x8000)
				{
					if (!amuletN.empty())
					{
						cls();
						cout << amuletN << endl << amuletDesc;
						if (amuletHP != 0)
							cout << "\nHealth: " << amuletHP;
						if (amuletAtk != 0)
							cout << "\nDamage: " << amuletAtk;
						if (amuletDef != 0)
							cout << "\nArmor: " << amuletDef;
						pause();
						goto equipment;
					}
					else
					{
						cls();
						cout << "SUPER EPIC EQUIPMENT MENU\n\n1. Weapon:	" << weaponN << "\n2. Armor:	" << armorN << "\n3. Amulet:	You do not have amulet!!!" << amuletN << "\n4. Back";
						goto retry;
					}
				}
				else if (GetAsyncKeyState(VK_KEY_4) & 0x8000 || GetAsyncKeyState(VK_NUMPAD4) & 0x8000)
				{ 
					goto stats;
				}
			}
		}
		else if (GetAsyncKeyState(VK_KEY_2) & 0x8000 || GetAsyncKeyState(VK_NUMPAD2) & 0x8000)
		{
			break;
		}
	}
	cls();
}

void player::giveName()
	{
		getline(cin >> ws, name);
	}

void player::chooseClass()
{
	bool check = false;
	cout << "Choose your class\n\n1. Tank\n2. Jew\n3. Battle man\n";
	while (check == false)
	{
		_getch();
		if (GetAsyncKeyState(VK_KEY_1) & 0x8000 || GetAsyncKeyState(VK_NUMPAD1) & 0x8000)
		{
			check = 1;
			health = 150.f;
			maxhealth = health;
			atk = 7.f;
			def = 20;
			shekels = 15;
		}
		else if (GetAsyncKeyState(VK_KEY_2) & 0x8000 || GetAsyncKeyState(VK_NUMPAD2) & 0x8000)
		{
			check = 1;
			health = 50.f;
			maxhealth = health;
			atk = 2.f;
			def = 0;
			shekels = 5000;
		}
		else if (GetAsyncKeyState(VK_KEY_3) & 0x8000 || GetAsyncKeyState(VK_NUMPAD4) & 0x8000)
		{
			check = 1;
			health = 100.f;
			maxhealth = health;
			atk = 10.f;
			def = 10;
			shekels = 15;
		}
	}
}

float player::attack(int x)
{
	srand((unsigned int)time(nullptr));
	float damage;
	switch (x)
	{
	case 1:
		damage = (atk + weaponAtk + amuletAtk) * 1.5;
		if (rand() % 100 < 45)
		{
			return damage;
		}
		else
			return 0.f;
	case 2:
		damage = (atk + weaponAtk + amuletAtk);
		if (rand() % 100 < 75)
		{
			return damage;
		}
		else
			return 0.f;
	case 3:
		damage = (atk + weaponAtk + amuletAtk) * 0.85;
		if (rand() % 100 < 90)
		{
			return damage;
		}
		else
			return 0.f;
	}
	return 0;
}
void player::equip(int equip, float hp, float damage, int defense, string name, string description)
{
	if (equip == 1)
	{
		weaponAtk = damage;
		weaponN = name;
		weaponDesc = description;
	}
	else if (equip == 2)
	{
		armorDef = defense;
		armorN = name;
		armorDesc = description;
	}
	else if (equip == 3)
	{
		amuletAtk = damage;
		amuletHP = hp;
		amuletDef = defense;
		amuletN = name;
		amuletDesc = description;
	}
}

void player::takeDamage(float x)
{
	float dmg;
	float dmgMult = x / (x + def + armorDef + amuletDef);
	dmg = x * dmgMult;
	health = health - dmg;
	cls();
	cout << "You took " << setprecision(2) << fixed << dmg << " damage.\n You have " << health << " health left" << endl;
	pause();
	cls();
}

int player::offer()
{
	return shekels;
}

void player::pay(int x)
{
	shekels -= x;
}
