#pragma once
#include <string>
using std::string;

class item
{
private:
	string name;
	string description;
	int price;
public:
	void readItem(float x);
	item(string n, string desc, int p);
};

class weapon : public item
{
private:
	float weaponAttack;
public:
	weapon(string n, string desc, int p, float attack) : item(n, desc, p) { weaponAttack = attack; };
	float x = weaponAttack;
};

class armor : public item
{
private:
	int armorDefense;
public:

};

class amulet : private item
{
private:
	float amuletHP;
	float amuletAtk;
	int amuletDef;
public:

};