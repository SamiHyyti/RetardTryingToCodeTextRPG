#pragma once
#include <string>
using std::string;

class enemy
{
protected:
	string enemyName;
	float health;
	int armor;
	float damage;
	float level;
public:
	float attack();
	void stats(float h, int a, float d, float l, string n);
	void readStats();
	float alive();
	void takeDamage(float x);
};