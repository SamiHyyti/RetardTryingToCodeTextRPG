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
	int itemID;
	void readName();
	void readItem(float x);
	item(string n, string desc, int p, int id);
};

class weapon : public item
{
private:
	float weaponAttack;
public:
	weapon(string n, string desc, int p, int id, float attack) : item(n, desc, p, id), weaponAttack(attack), x(weaponAttack)
	{}

	float const & x;
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