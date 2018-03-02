#include "includes.h"
using namespace std;

float enemy::attack()
	{
		srand((unsigned int)time(nullptr));
		float dmg = damage + damage * level;
		int x = rand() % 100 + 1;
		if (x < 51)
		{
			if (rand() % 100 < 75)
			{
				return dmg;
			}
			else
				return 0;
		}
		else if (x < 81)
		{
			if (rand() % 100 < 85)
			{
				return dmg * 0.85;
			}
			else
				return 0;
		}
		else
		{
			if (x < 55)
			{
				return dmg * 1.5;
			}
			else
				return 0;
		}
	}

	void enemy::stats(float h, int a, float d, float l, string n, int b)
	{
		health = h;
		armor = a;
		damage = d;
		level = l;
		enemyName = n;
		bounty = b;
	}

	void enemy::readStats()
	{
		cls();
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
		health = health - dmg;
		cls();
		cout << "Enemy took " << setprecision(2) << fixed << dmg << " damage\n";
		pause();
		cls();
	}
	int enemy::givebounty()
	{
		return bounty;
	}
