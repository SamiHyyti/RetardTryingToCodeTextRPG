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
	string t1,t2,t3;
	float a=0,b=0,c=0;
	void readName();
	void readItem();
	item(string n, string desc, int p, int id);
};

class weapon : public item
{
private:
	float weaponAttack;
public:
	weapon(string n, string desc, int p, int id, float attack) : item(n, desc, p, id), weaponAttack(attack), x(weaponAttack)
	{
		a = x;
		t1 = "Damage: ";
	}
	float const &x;
};

class armor : public item
{
private:
	int armorDefense;
public:
	armor(string n, string desc, int p, int id, int armor) : item(n, desc, p, id), armorDefense(armor), y(armorDefense)
	{
		a = y;
		t1 = "Defense: ";
	}

	int const &y;
};

class amulet : public item
{
private:
	float amuletHp;
	float amuletAtk;
	int amuletDef;
public:
	amulet(string n, string desc, int p, int id, int def, float hp, float atk) : item(n, desc, p, id), amuletDef(def), amuletHp(hp), amuletAtk(atk), x(amuletHp), y(amuletAtk), z(amuletDef)
	{
		a = x;
		b = y;
		c = z;
		t1 = "Health: ";
		t2 = "Damage: ";
		t3 = "Defense: ";
	}

	float const &x;
	int const &y, &z;
};