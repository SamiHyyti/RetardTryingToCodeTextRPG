#include "includes.h"
using namespace std;

item::item(string n, string desc, int p,int id)
{
	name = n;
	description = desc;
	price = p;
	itemID = id;
}

void item::readItem(float x)
{
	cout <<  name << endl << description << endl << price << endl << fixed << setprecision(0) << x << endl;
	system("pause");
}

void item::readName()
{
	cout << itemID <<". " << name << endl;
}