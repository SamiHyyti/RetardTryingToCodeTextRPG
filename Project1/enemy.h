#pragma once
#include <string>
using std::string;

class enemy
{
private:
	string enemyName;
	float health;
	int armor;
	float damage;
	float level;
	int bounty;
public:
	float attack();
	void stats(float h, int a, float d, float l, string n, int b);
	void readStats();
	float alive();
	void takeDamage(float x);
	int givebounty();
};