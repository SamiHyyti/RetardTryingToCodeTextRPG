#pragma once
#include <vector>
using std::vector;

void createWeapon(string n, string d, int p, int id, float atk);
void createArmor(string n, string d, int p, int id, int def);
void createAmulet(string n, string d, int p, int id, int def, float hp, float atk);


void createItems();


void choise(int x);

void print();

void inspect();