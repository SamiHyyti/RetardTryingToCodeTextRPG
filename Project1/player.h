#pragma once
#include <string>
using std::string;

class player
{
private:
	string name;
	float health = health + amuletHP;
	float atk = atk + weaponAtk + amuletAtk; //3 rivi� vammaista koodia jotka tulee haittaamaan my�hemmin
	int def = def + armorDef + amuletDef;
	int shekels;
	string weaponN;
	string weaponDesc;
	int weaponAtk;
	string armorN;
	string armorDesc;
	int armorDef;
	string amuletN;
	string amuletDesc;
	int amuletHP;
	int amuletAtk;
	int amuletDef;
public:
	float alive();
	void readStats();
	void giveName();
	void chooseClass();
	float attack(int x);
	void equip();
	void takeDamage(float x);
};