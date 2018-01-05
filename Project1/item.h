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
	weapon(string n, string desc, int p, int id, float attack) : item(n, desc, p, id), weaponAttack(attack),x(weaponAttack)
	{}
	
	float const & x;
};

class armor : public item
{
private:
	int armorDefense;
public:
	armor(string n, string desc, int p, int id, int armor) : item(n, desc, p, id), armorDefense(armor), x(armorDefense)
	{}

	float const & x;
};

class amulet : public item
{
private:
	float amuletHp;
	float amuletAtk;
	int amuletDef;
public:
	amulet(string n, string desc, int p, int id, int def, float hp, float atk) : item(n, desc, p, id), amuletDef(def), amuletHp(hp), amuletAtk(atk),x(amuletHp),y(amuletAtk),z(amuletDef)
	{}

	float const & x,y,z;
};