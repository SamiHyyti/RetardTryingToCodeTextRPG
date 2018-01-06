#include "includes.h"
using namespace std;

float enemy::attack()
	{
		float dmg;
		dmg = damage + damage * level;
		return dmg;
	}

	void enemy::stats(float h, int a, float d, float l, string n)
	{
		health = h;
		armor = a;
		damage = d;
		level = l;
		enemyName = n;
	}

	void enemy::readStats()
	{
		system("cls");
		cout << "you are fighting: " << enemyName << endl << enemyName<< " Health: " << setprecision(2)<<fixed <<health << endl;
	}

	float enemy::alive()
	{
		return health;
	}

	void enemy::takeDamage(float x)
	{
		float dmg;
		float dmgMult = x / (x + armor);
		dmg = x * dmgMult;
		if (armor == 0)
			health = health - x;
		else;
		health = health - dmg;
		system("cls");
		cout << "Enemy took " << setprecision(2) << fixed << dmg << " damage\n";
		system("pause");
		system("cls");
	}

