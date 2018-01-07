#include "includes.h"
using namespace std;

float player::alive()
{
	return health;
}

void player::readStats()
{
	cls();
	cout << name << endl << "health: " << setprecision(2) << fixed << health << "/" << setprecision(0) << fixed << maxhealth << endl << "attack: " << atk << endl << "defense: " << def << endl << "shekels: " << shekels << endl << endl;
	pause
	cls();
}

void player::giveName()
	{
		getline(cin >> ws, name);
	}

void player::chooseClass()
{
	int selection;
	bool check = false;
	cout << "Choose your class\n\n1. Tank\n2. Jew\n3. Battle man\n\nSelection: ";
retry:
	while (!(cin >> selection))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cls();
		cout << "Choose your class\n\n1. Tank\n2. Jew\n3. Battle man\n\nSelection: ERROR invalid selection";
		Sleep(1000);
		cls();
		cout << "Choose your class\n\n1. Tank\n2. Jew\n3. Battle man\n\nSelection: ";
	}
	switch (selection)
	{
	case 1:
		check = 1;
		health = 150.f;
		maxhealth = health;
		atk = 7.f;
		def = 20;
		shekels = 15;
		break;
	case 2:
		check = 1;
		health = 50.f;
		maxhealth = health;
		atk = 2.f;
		def = 0;
		shekels = 500;
		break;
	case 3:
		check = 1;
		health = 100.f;
		maxhealth = health;
		atk = 10.f;
		def = 10;
		shekels = 15;
		break;
	default:
		cls();
		cout << "Choose your class\n\n1. Tank\n2. Jew\n3. Battle man\n\nSelection: ERROR invalid selection";
		Sleep(1000);
		cls();
		cout << "Choose your class\n\n1. Tank\n2. Jew\n3. Battle man\n\nSelection: ";
		goto retry;
	}
}

float player::attack(int x)
{
	srand((unsigned int)time(nullptr));
	float damage;
	switch (x)
	{
	case 1:
		damage = atk * 1.5;
		if (rand() % 100 < 45)
		{
			return damage;
		}
		else
			return 0.f;
	case 2:
		damage = atk;
		if (rand() % 100 < 75)
		{
			return damage;
		}
		else
			return 0.f;
	case 3:
		damage = atk * 0.85;
		if (rand() % 100 < 90)
		{
			return damage;
		}
		else
			return 0.f;
	}
	return 0;
}
void player::equip()
{
}
void player::takeDamage(float x)
{
		float dmgMult = x / (x + def);
		float dmg = x * dmgMult;
		int y = rand() % 100 + 1;
		if (y < 51)
		{
			if (rand() % 100 < 75)
			{
			}
			else
				dmg = 0.0f;
		}
		else if (y < 81)
		{
			if (rand() % 100 < 85)
			{
				dmg = dmg * 0.85;
			}
			else
				dmg = 0.0f;
		}
		else
		{
			if (rand() % 100 < 55)
			{
				dmg = dmg * 1.5;
			}
			else
				dmg = 0.f;
		}
	if (dmg != 0)
	{
		health = health - dmg;
		cls();
		cout << "you took " << setprecision(2) << fixed << dmg << " damage.\n You have " << health << " health left" << endl;
		pause
		cls();
	}
	else
	{
		cls();
		cout << "The enemy attack missed you!\n";
		pause
		cls();
	}
}