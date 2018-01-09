#pragma once
#include <vector>
#include <string>
using std::string;

class player
{
private:
	string name;
	float maxhealth;
	float health;
	float atk;
	int def;
	int shekels;
	string weaponN;
	string weaponDesc;
	int weaponAtk = 0;
	string armorN;
	string armorDesc;
	int armorDef = 0;
	string amuletN;
	string amuletDesc;
	int amuletHP = 0;
	int amuletAtk = 0;
	int amuletDef = 0;
public:
	float alive();
	void readStats();
	void giveName();
	void chooseClass();
	float attack(int x);
	void equip(int equip, float hp, float damage, int defense);
	void takeDamage(float x);
	int offer();
	void pay(int x);
};