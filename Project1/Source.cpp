#include "includes.h"
#include "items.h"
#include <vector>
#include <fstream>
#include <ostream>
using namespace std;
player Player;
enemy Enemy;
float percentage = 0.f;
void combatMenu();
void youmissed()
{
	cls();
	cout << "Your attack missed!\n";
	pause();
}
void mainMenu()
{
	string menutext = "text monster killing RPG v0.15 early acces alpha\n\n1. New game\n2. Quit game\n";
	cout << menutext;
	while (1)
	{
		_getch();
		if(GetAsyncKeyState(VK_KEY_1) & 0x8000 || GetAsyncKeyState(VK_NUMPAD1) & 0x8000)
		{
			cls();
			return;
		}
		else if (GetAsyncKeyState(VK_KEY_2) & 0x8000 || GetAsyncKeyState(VK_NUMPAD2) & 0x8000)
		{
			exit(1);
		}
	}

}

void generateEnemy()
{
	int x = rand() % 100 + 1;
	if (x < 51)
	{
		Enemy.stats(10.f + 10.f * percentage, 0, 10.f, percentage, "Goblin");
	}
	else if (x < 81)
	{
		Enemy.stats(20.f + 20.f * percentage, 4, 15.f, percentage, "Orc");
	}
	else
	{
		Enemy.stats(50.f + 50.f * percentage, 10, 20.f, percentage, "Troll");
	}
}

void battle()
{
	bool menu = true;
	retry:
	Enemy.readStats();
	cout << "\n\n1. Attack Enemy\n2. Flee the battle\n";
	while (menu == true)
	{
		_getch();
		if (GetAsyncKeyState(VK_KEY_1) & 0x8000 || GetAsyncKeyState(VK_NUMPAD1) & 0x8000)
		{
			combatMenu();
			if (Enemy.alive() > !0.0f)
			{
				Player.takeDamage(Enemy.attack());
				if (Player.alive() > !0.0f)
					goto retry;
				else
				{
					cls();
					cout << "YOU DIED\nGAME OVER!\n";
					pause();
					exit(3);
				}
			}
			else if (Enemy.alive() > !0.0f)
				goto retry;
			else
			{
				menu = false;
				percentage += 0.01f;
			}
		}
		else if (GetAsyncKeyState(VK_KEY_2) & 0x8000 || GetAsyncKeyState(VK_NUMPAD2) & 0x8000)
		{
			menu = false;
			if (percentage != 0.00f)
			{
				percentage -= 0.01f;
				cls();
				break;
			}
			cls();
		}

	}
}

void characterCreation()
{
	cout << "Enter the name of your character: ";
	Player.giveName();
	cls();
	Player.chooseClass();
	cls();
}

void shop()
{
	int selection;
	print();
	inspect();
	cls();

}

void adventureMenu()
{
	string selectiontext = "1. battle random enemy\n2. current stats and equipment\n3. shop(TEST PHASE)\n4. quit\n";
retry:
	cout << selectiontext;
	while (1)
	{
		_getch();
		if (GetAsyncKeyState(VK_KEY_1) & 0x8000 || GetAsyncKeyState(VK_NUMPAD1) & 0x8000)
		{
			generateEnemy();
			Sleep(100);
			battle();
			goto retry;
		}
		else if (GetAsyncKeyState(VK_KEY_2) & 0x8000 || GetAsyncKeyState(VK_NUMPAD2) & 0x8000)
		{
			Player.readStats();
			goto retry;
		}
		else if (GetAsyncKeyState(VK_KEY_3) & 0x8000 || GetAsyncKeyState(VK_NUMPAD3) & 0x8000)
		{
			shop();
			cls();
			goto retry;
		}
		else if (GetAsyncKeyState(VK_KEY_4) & 0x8000 || GetAsyncKeyState(VK_NUMPAD4) & 0x8000)
		{
			exit(2);
		}
	}

}

void combatMenu()
{
	bool menu = true;
	float x;
	cls();
	cout << "1. Strong Attack\n2. Normal Attack\n3. Quick Attack\n";
	while (menu == true)
	{
		_getch();
		if (GetAsyncKeyState(VK_KEY_1) & 0x8000 || GetAsyncKeyState(VK_NUMPAD1) & 0x8000)
		{
			x = Player.attack(1);
			if (x != 0)
				Enemy.takeDamage(x);
			else
				youmissed();
			menu = false;
		}
		else if (GetAsyncKeyState(VK_KEY_2) & 0x8000 || GetAsyncKeyState(VK_NUMPAD2) & 0x8000)
		{
			x = Player.attack(2);
			if (x != 0)
				Enemy.takeDamage(x);
			else
				youmissed();
			menu = false;
		}
		else if (GetAsyncKeyState(VK_KEY_3) & 0x8000 || GetAsyncKeyState(VK_NUMPAD3) & 0x8000)
		{
			x = Player.attack(3);
			if (x != 0)
				Enemy.takeDamage(x);
			else
				youmissed();
			menu = false;
		}
	}
}

int main()
{
	createItems();
	srand((unsigned int)time(nullptr));
	mainMenu();
	Sleep(10);
	characterCreation();
	Player.readStats();
	cls();
	adventureMenu();
	return 0;
}