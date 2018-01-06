#include "includes.h"
using namespace std;

item::item(string n, string desc, int p, int id)
{
	name = n;
	description = desc;
	price = p;
	itemID = id;
}

void item::readItem()
{

	if (a != 0)//weapon,armor,amulet of health
	{
		cout << name << endl << description << endl << price << endl << t1 << fixed << setprecision(0) << a << endl;
	}
	else if (b != 0)//amulet of attack
	{
		cout << name << endl << description << endl << price << endl<< t2 << b << endl;
	}
	else if (c != 0)//amulet of defense
	{
		cout << name << endl << description << endl << price << endl << t3 << c << endl;
	}
	else//amulet of suprem powre my dude
	{
		cout << name << endl << description << endl << price << endl << fixed << setprecision(0)<< t1 << a << endl << t2 << b << endl << t3 << c << endl;
	}
}

void item::readName()
{
	cout << itemID <<". " << name << endl;
}