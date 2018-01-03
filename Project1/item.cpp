#include "includes.h"
using namespace std;

item::item(string n, string desc, int p)
{
	name = n;
	description = desc;
	price = p;
}

void item::readItem(float x)
{
	cout <<  name << endl << description << endl << price << endl << fixed << setprecision(0) << x << endl;
	system("pause");
}

