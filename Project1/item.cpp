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

	if (a != 0)//amulet of health
	{
		cout << name << endl << description << endl << price << endl << t1 << fixed << setprecision(0) << a << endl;
	}
	else if (b != 0)//amulet of attack,weapon
	{
		cout << name << endl << description << endl << price << endl<< t2 << b << endl;
	}
	else if (c != 0)//amulet of defense,marmor
	{
		cout << name << endl << description << endl << price << endl << t3 << c << endl;
	}
	else//amulet of suprem powre my dude
	{
		cout << name << endl << description << endl << price << endl << fixed << setprecision(0)<< t1 << a << endl << t2 << b << endl << t3 << c << endl;
	}
}

int item::receivePayment()
{
	return price;
}

void item::readName()
{
	cout << name << endl;
}

int item::checkID()
{
	return itemID;
}

float item::retHp()
{
	return a;
}
float item::retDmg()
{
	return b;
}
int item::retDef()
{
	return c;
}

string item::retNa()
{
	return name;
}
string item::retDe()
{
	return description;
}